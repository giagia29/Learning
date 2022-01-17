#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 5000000
#define NUM_THREADS 6

int part_size, p = 0;
int sum[NUM_THREADS] = { 0 };

int total = 0;
int n1, n2;
char *s1, *s2;

FILE *fp;

pthread_mutex_t mutex;

int readf(char* filename)
{
    if( (fp = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: can't open %s!\n", filename);
        return 0;
    }

    s1 = (char*) malloc(sizeof(char) * MAX);

    if(s1 == NULL)
    {
        printf("ERROR: Out of memory!\n");
        return -1;
    }

    s2 = (char*) malloc(sizeof(char) * MAX);

    if(s2 == NULL)
    {
        printf("ERROR: Out of memory!\n");
        return -1;
    }

    s1 = fgets(s1, MAX, fp);
    s2 = fgets(s2, MAX, fp);
    n1 = strlen(s1);
    n2 = strlen(s2) - 1;

    if(s1 == NULL || s2 == NULL || n1 < n2)
    {
        return -1;
    }
}

void* num_substring(void* arg)
{
    int i, j, k;
    int count;

    pthread_mutex_lock(&mutex);

    int value = *(int*)arg;

    for(i = value; i <= (value + part_size - n2); i++)
    {
        count = 0;
        for(j = i, k = 0; k < n2; j++, k++)
        {
            if( *(s1 + j) != *(s2 + k) )
            {
                break;
            }
            else
            {
                count++;
            }

            if(count == n2)
            {
                sum[p]++;
            }
        }
    }
    p++;

    pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("ERROR: You must pass in the datafile as a command line parameter\n\n");
    }

    readf( argv[1] );

    struct timeval start, end;
    float mtime;
    int secs, usecs;

    pthread_t tid[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    gettimeofday(&start, NULL);

    part_size = n1 / NUM_THREADS;

    int i, a, x[NUM_THREADS] = { 0 }, j = 0; //x array holds the start index of the partitioned string

    for(i = 0; i < NUM_THREADS; i++)
    {
        a = i * part_size;
        x[j] = a;
        if( pthread_create(&tid[i], NULL, &num_substring, (void*)&x[j]) != 0 )
        {
            perror("Failed to create thread\n");
        }
        j++;
    }

    for(i = 0; i < NUM_THREADS; i++)
    {
        if( pthread_join(tid[i], NULL) != 0 )
        {
            perror("Failed to join thread\n");
        }
    }

    for(i = 0; i < NUM_THREADS; i++)
    {
        total = total + sum[i];
    }

    pthread_mutex_destroy(&mutex);

    gettimeofday(&end, NULL);

    secs = end.tv_sec - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    mtime = ((secs) * 1000 + usecs/1000.0) + 0.5;

    printf("\nThe number of substring is: %d\n", total);
    printf("\nElapsed time is %f milliseconds\n\n", mtime);

    if( s1 )
    {
        free(s1);
    }

    if( s2 )
    {
        free(s2);
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define MAX 10000
#define NUM_BUFFER 5

sem_t semFull, semVacant;
char buffer[NUM_BUFFER];
char *s;
int i = 0, rear = 0, front = 0;

FILE *fp;

void* producer( void* arg )
{
    printf("Producer thread created:\n");
    while( s[i] != '\0' )
    {
        sem_wait(&semVacant);
        buffer[rear] = s[i];
        printf("\nProduced: %c\n", buffer[rear]);
        rear = (rear + 1) % NUM_BUFFER;
        i++;
        sem_post(&semFull);
        sleep(1);
    }
}

void* consumer( void* arg )
{
    printf("Consumer thread created:\n");
    char temp;
    while( s[i] != '\0' )
    {
        sem_wait(&semFull);
        temp = buffer[front];
        printf("Consumed: %c\n", temp);
        front = (front + 1) % NUM_BUFFER;
        sem_post(&semVacant);
        sleep(1);
    }
}

int readfile(char *filename)
{
    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf("ERROR: can't open %s!\n", filename);
        return 0;
    }
    
    s = (char*) malloc(sizeof(char) * MAX);

    if( s == NULL )
    {
        printf("ERROR: Out of memory!\n");
        return -1;
    }

    s = fgets(s, MAX, fp);
}


int main(int argc, char* argv[])
{
    if ( argc < 2 )
    {
        printf("ERROR: You must pass in the datafile as a command line parameter\n");
    }

    readfile( argv[1] );

    sem_init(&semFull, 0, 0);
    sem_init(&semVacant, 0, NUM_BUFFER);

    pthread_t producer_tid;
    pthread_t consumer_tid;

    pthread_create(&producer_tid, NULL, &producer, NULL);
    pthread_create(&consumer_tid, NULL, &consumer, NULL);

    sem_destroy(&semFull);
    sem_destroy(&semVacant);

    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    if( s )
    {
        free(s);
    }

    return 0;
}
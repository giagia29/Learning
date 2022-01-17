#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void signal_handler(int signum)
{
    printf("Time remaining: ");
}
int main()
{
    int i;
    signal(SIGALRM, signal_handler);
    pid_t pid = fork();
    int second = 10;
    if (pid != 0)
    {
        wait(NULL);
        printf("\nCountdown complete\n");
    }
    else
    { 
        while(second >= 0)
        {
            alarm(1);
            sleep(1);
            printf("%d\n", second);
            second = second - 1;
        } 
    }
    return 0;
}
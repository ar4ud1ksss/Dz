#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
    {
    printf("my ID:%d\nEnter N\n", getpid());
    int N;
    scanf ("%d",&N);
    int pid;
    int status = 1;
    for (int i = 0; i < N-1; i++)    
        {
        pid = fork ();
        if (pid == 0)
            {
            printf ("I:%d; parents:%d\n",getpid(),getppid());
            }
            
        else
            {
            wait(&status);
            printf("Child №%d died.\n", pid);
            printf ("Now is %d\n", getpid());
            exit (0);
            }
        
        }
    }


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
    {
    int N;
    FILE* data = fopen("data.txt","r");
    fscanf (data,"%d\n",&N);
    //printf ("%d\n",N);
    int j = 0;
    char* A = (char*) calloc (1024,sizeof(char));
    char** B = (char**) calloc (N,sizeof(char*));
    for (int i = 0; i < N; i++)        
        {           
        fgets (A + j, 100, data);  
        j = strlen (A);
        
        }
    int length = strlen (A);
    B[0] = A;
    int n = 1;
    for (int i = 0; i < length; i++)
        if (A[i] == '\n')
            {            
            B[n] = &A[i]+1;
            A[i] = '\0';
            n++;
            }

    int pid;
    int status = 1;          
    for (int i = 0; i < N; i++)    
        {        
        pid = fork();
        if (pid == 0)
            {
            char* C = strchr (B[i],' ');
            *C = '\0';
            char* D = strchr (C+1,' ');
            *D = '\0';
            sleep(atoi(B[i]));
            execlp (C+1, C+1, D+1, NULL);
            }
        }    
    }

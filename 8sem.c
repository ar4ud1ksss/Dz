#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <dirent.h>
#include <sys/stat.h>

char* searching(int* n, char* curpath, char* search_name);

int main(int argc, char *argv[])
    {
    DIR* dir = opendir("..");
    int count = 0;
    struct dirent *temp = readdir(dir);
    struct stat buf;
    char* search_name = argv[1];
    int n = 0;
    for(int i = 0; i < strlen(argv[2]); i++)
	    {
        n = argv[2][i] - '0';
    	}
    char* name = searching(&n, ".", search_name);
    printf("name = %s\n", name);
    }

char* searching(int* n, char* curpath, char* search_name)
    {
    DIR* dir = opendir(curpath);
    struct dirent *temp = readdir(dir);
    char* name = (char*) calloc (17, sizeof(char));
    struct stat buf;
    while(temp)
        {
        strcpy(name, curpath);
        strcat(name, "/");
        strcat(name, temp -> d_name);
        if(strcmp(temp -> d_name, ".") != 0 && strcmp(temp -> d_name, "..") != 0)
            {
            stat(name, &buf);
            int type = 0;
            if (S_ISREG(buf . st_mode))
                {
                if(strcmp(search_name , temp -> d_name) == 0)
                    {
                    return name;
                    }
                }
            if(S_ISDIR(buf . st_mode))
                {
                if (*n > 0)
                    {
                    *n--;
                    char* temp1 = NULL;
                    temp1 = searching(n, name, search_name);
                    if (temp1)
                        return temp1;
                    }
                }
            }
            temp = readdir(dir);
        }
        free(name);
    }

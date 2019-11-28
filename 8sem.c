#include <dirent.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Find(char* target, DIR* dir, char* stream);

int main(int depth, char* title[])
    {
    DIR* dir = opendir(".");
    char* dis = (char*)calloc(17, sizeof(char));
    dis = Find(title[1], dir, ".");
    printf("%s\n", dis);
    closedir (dir);
    return 0;
    }

char* Find(char* target, DIR* dir, char* stream)
    {
    struct dirent* entry;
    struct stat buff;
    char* name = (char*)calloc(17, sizeof(char));
    while((entry = readdir(dir)) != NULL)
        {
        strcpy(name, stream);
        strcat(name, "/");
        strcat(name ,entry->d_name);
        stat(name, &buff);
        if(S_ISREG(buff.st_mode) == 0 && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            return Find(target, dir, name);
        if(strcmp(target, entry->d_name) == 0)
            return name;
            
        }
    }

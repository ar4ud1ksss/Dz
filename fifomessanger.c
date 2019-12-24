#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

void *mythread1(void *names);
void *mythread2(void *names);
void chatting(char* nametoread, char* nametowrite);

int main(int argc, char** argv)
    {
    int result;
    size_t size;
    char resstring[14];
    char name01[]="aaaa.fifo";
    char name10[] = "aaa.fifo"; 
    (void)umask(0);
    mknod(name01, S_IFIFO | 0666, 0);
    mknod(name10, S_IFIFO | 0666, 0);
    if (strcmp(argv[1], "0") == 0)
        {
        chatting(name10, name01);
        }
    if (strcmp(argv[1], "1") == 0)
        {
        chatting(name01, name10);
        }
    return 0;
    }

void chatting(char* nametoread, char* nametowrite){
    pthread_t thid, secthid;
    pthread_create( &thid, (pthread_attr_t *)NULL, mythread1, nametoread);
    pthread_create( &secthid, (pthread_attr_t *)NULL, mythread2, nametowrite);
    pthread_join(thid, (void **)NULL);
    pthread_join(secthid, (void**)NULL);
}

void *mythread1(void *names)
    {
    pthread_t mythid;
    mythid = pthread_self();
    int fdw = open((char*)names, O_WRONLY);
    while(1)
        {
        char buf[100];
        memset(buf, 0, 100);
        fgets(buf, 100, stdin);
        write(fdw, buf, 100);
        memset(buf, 0, 100);
        }
    return NULL;
    }

void *mythread2(void *names)
    {
    pthread_t mythid;
    mythid = pthread_self();
    int fwr = open((char*)names, O_RDONLY);
    while(1)
        {
        char buf[100];
        memset(buf, 0, 100);
        read(fwr, buf, 100);
        printf("%s", buf);
        memset(buf, 0, 100);
        }
    return NULL;
    }


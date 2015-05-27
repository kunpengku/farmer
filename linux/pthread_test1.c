#include "apue.h"
#include <pthread.h>

void printids(const char* s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (%0x%s) \n" , s, (unsigned int) pid, 
            (unsigned int) tid, (unsigned  int ) tid);
}

void * thr_fn(void *arg)
{
    printids("new thread :  ");
    return (void *)0;
}
pthread_t ntid;

int main()
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if(err != 0)
        printf("error\n");
    printids("main thread:");
    sleep(1);

    exit(0);
    
}
~        

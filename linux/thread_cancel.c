#include "apue.h"
#include <pthread.h>

/*
 * 线程的 退出处理函数 ， 线程在正常退出时候，是不会调用 线程处理函数的 ，如thread1. 
 *
 *
 */
void cleanup(void *arg)
{
    printf("cleanup:%s\n" , (char *)arg);
}

void * thr_fn1(void *arg)
{
    printf("thread 1 start  arg:\n");
    pthread_cleanup_push(cleanup, "thread 1 first hander");
    pthread_cleanup_push(cleanup, "thread 1 second hander");
    printf("thread 1 push complete\n");

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return (void *)31;
}

void * thr_fn2(void *arg)
{
    printf("thread 2 start  arg:\n");
    pthread_cleanup_push(cleanup, "thread 2 first hander");
    pthread_cleanup_push(cleanup, "thread 2 second hander");
    printf("thread 2 push complete\n");

    pthread_cleanup_pop(0);
    pthread_exit((void *)61);
    pthread_cleanup_pop(0);

}
int main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, (void *) 2);
    if (err != 0)
        printf("error\n");

    err = pthread_join(tid1, &tret);
    printf("thread return code %d\n" , tret);


    err = pthread_create(&tid2, NULL, thr_fn2, (void *) 4);
    if (err != 0)
        printf("error\n");

    err = pthread_join(tid2, &tret);
    printf("thread 2 return code %d\n" , tret);

    

    exit(0);
}

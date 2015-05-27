#include "apue.h"
#include <pthread.h>

/*
 * 线程返回退出状态的两种方式  return 和 pthread_exit()
 */
void *thr_fn1(void * arg)
{
    printf("thread 1 returning\n");
    return ((void *) 10);
}

void * thr_fn2(void* arg)
{
    printf("thread 2 exit\n");
    pthread_exit((void *) 99);
    
}
int main()
{
    int err;
    pthread_t tid1,tid2;
    void * tret;

    //1
    err = pthread_create(&tid1, NULL, thr_fn1,NULL);
    if (err != 0)
        printf("error\n");
    err = pthread_join(tid1, &tret);
    if (err != 0)
        printf("error\n");
    printf("thread 1 return %d\n" , (int)tret);

    //2
    err = pthread_create(&tid2, NULL, thr_fn2,NULL);
    if (err != 0)
        printf("error\n");
    err = pthread_join(tid2, &tret);
    if (err != 0)
        printf("error\n");

    printf("thread 2 exit %d\n" , (int)tret);


    exit(0);
}

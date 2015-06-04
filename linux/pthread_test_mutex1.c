#include <stdlib.h>
#include <pthread.h>

struct foo {
    int f_count;
    pthread_mutex_t  f_lock;
};

struct foo * foo_alloc(void)
{
    struct foo *fp;
    if ((fp = malloc(sizeof(struct foo))) != NULL)
    {   
        fp->f_count = 1;
        if (pthread_mutex_init( &fp->f_lock, NULL ) != 0){ 
            //互斥量 初始化失败
            free(fp);
            return NULL;
        }   
        /* continue initialization */
    }   

    return fp; 
}

// f_count ++
void  foo_hold( struct foo *fp )
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count ++; 
    pthread_mutex_unlock(&fp->f_lock);
}

// f_count --
void foo_release(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);
    if (-- fp->f_count == 0){ /* last reference */
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destory(& fp->f_lock);
        free(fp);
    }else{
        pthread_mutex_unlock(&fp->f_lock);
    }   
}

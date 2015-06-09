#include <stdio.h>
#include <sys/time.h>
#include <time.h>


int main()
{
    int a = 999999999;
    struct timespec tv;
    tv.tv_sec = 0;
    tv.tv_nsec = a;

    while(1)
    {
        nanosleep(&tv,NULL);
        printf("__fupeng))  %d\n", a);
    
    }

}
// 当用timespec 这个结构 来表示 3.1秒时候， 必须 拆开写成3秒+ 100 000 000纳秒，
//而不能全部写到纳秒上 3100 000 000 。 这样会使得 sleep的时间和你想的很不一样。

#include <stdio.h>

void bubble_sort(int a[], int len)
{
    int i,j,tmp;

    for(i=0 ; i < len-1 ; i++)
    {   
        for(j=0; j < len-i-1; j++)
        {   

            if(a[j+1] < a[j]){
                tmp = a[j];
                a[j] =a[j+1];
                a[j+1] = tmp;
            }   
        }   
    }   

}

int main(){

    int tmp[] = {1,2,5,7,1,0,2,345,15,-9,22,56,78,99};
    int buf[100]={0};

    printf("len is %d\n\n", len);

    //merge_sort(tmp,0,len-1, buf);
    bubble_sort(tmp,len);

    int i;
    for ( i=0; i< len; i++)
    {   
        printf("%d\n", tmp[i]);
    }   
    return 0;

}

#include <stdio.h>

void insert_sort(int a[], int len)
{
    int i,j,k;

    for(i=1 ; i < len ; i++)
    {   
        //a[i]
        for(j = i-1; j >= 0; j--){
            if(a[i] > a[j])
                break;
        }   

        if( j!= i-1){
            int tmp = a[i];
            for(k = i-1; k> j; k--){
                a[k+1] = a[k];
            }   

            a[k+1] = tmp;
        }   
    }   

}

int main(){

    int tmp[] = {100,2,5,7,1,0,2,345,15,-9,22,56,78,99};
    int buf[100]={0};
    int len = sizeof(tmp)/sizeof(int);

    printf("len is %d\n\n", len);

    //merge_sort(tmp,0,len-1, buf);
    insert_sort(tmp,len);

    int i;
    for ( i=0; i< len; i++)
    {   
        printf("%d\n", tmp[i]);
    }   
    return 0;

}

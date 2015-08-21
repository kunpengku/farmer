#include <stdio.h>

// 平均 nlogn  最差 n^2
int quick_sort(int tmp[], int left, int right)

{

    int i,j,key,t;
    if(left > right)
        return;

    i = left;
    j = right;
    key = tmp[left];
    while(i != j){ 
        while(tmp[j]>=key && i < j ){
            j--;
        }   
        while(tmp[i] <= key && i < j){ 
            i++;
        }   
        if (i < j){ 
            t = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = t;
        }   

    }   
    tmp[left] = tmp[i];
    tmp[i] = key;

    quick_sort(tmp,left,i-1);
    quick_sort(tmp,i+1,right);



}

int main()
{
    int tmp[] = {10,2,4,5,7,1,9,8,6,0,3};
    int len = sizeof(tmp)/sizeof(int);
    printf("len=%d\n",len);
    quick_sort(tmp,0,len-1);
    int i=0;
    for(; i<len; i++){
        printf("%d\n", tmp[i]);
    }

    return 0;
}

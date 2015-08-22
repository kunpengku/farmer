#include<stdio.h>

void merge_array(int a[], int left, int mid, int right,int buf[])
{
    int i = left, j = mid+1;
    int m = mid, n = right;
    int k = 0;

    while(i <= m && j <= n){    // <=
        if(a[i] < a[j]){
            buf[k++] = a[i++];
        }else{
            buf[k++] = a[j++];
        }   
    }   
    while(i<=m)
        buf[k++] = a[i++];

    while(j<=n)
        buf[k++] = a[j++];

    for(i=0;i<k;i++)
        a[left + i] = buf[i];   //a[left + 1]

}

void merge_sort(int a[], int left, int right, int buf[])
{
    if(left < right)   //  <
    {   
        int mid = left + ((right-left)>>1);
        merge_sort(a, left, mid, buf);
        merge_sort(a, mid+1, right, buf);

        merge_array(a,left,mid,right,buf);
    }   

}

int main()
{
    int a[] = {12,2,45,-20,65,46,1,413,243,241,2,1,-3};
    int len = sizeof(a)/sizeof(int);
    int buf[30]={0};

    merge_sort(a,0,len-1,buf);

    int i;
    for(i=0;i<len;i++){
        printf("%d\n", a[i]);
    }

}

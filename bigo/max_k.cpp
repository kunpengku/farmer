#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int k;
//int a[20]={1,2,3,6,5,9,7,8,4,10,11,12,13,14,15,16,17,18,19,20};
int a[]={9,8,7,6,5,4,0,3,2,1};

int partition(int l,int r,int a[])
{
    int key=a[l],index=l;
    for(int i=l+1;i<=r;i++)
    {   
        if(a[i]<key)
         {   
             index++;
             swap(a[index],a[i]);
         }   
    }   
    swap(a[l],a[index]);
    return index;
}

void quickSort(int l, int r, int a[])
{
    if(l<=r)
    {   
        int mid = partition(l,r,a);
        printf("mid=%d\n", mid);
        if(mid == k)
            printf("find %d\n",k);

        if(k>=l&&k<=mid-1)
         quickSort(l,mid-1,a);
        else
         quickSort(mid+1,r,a);
    }   
}

int main()
{
    int i,n;

    k=1;
    n= sizeof(a)/sizeof(int);
    printf("len=%d\n",n);
    //// 因为下标是从0开始的， 所以 第k大的数字，下标是k-1
    k--;
    quickSort(0,n-1,a);

    for(i=0;i<n;i++)
     printf("%d ",a[i]);

    printf("\n");

    printf("k __ is %d\n",a[k]);
    return 0;
}

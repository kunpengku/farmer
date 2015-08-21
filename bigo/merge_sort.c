#include <stdio.h>

void merge_array(int a[], int  first, int mid, int last, int tmp[])
{
    int i=first,j=mid+1;
    int m=mid, n=last;
    int k=0;
    while(i<=m && j<= n)
    {   
        if(a[i] <= a[j])
        {   
            tmp[k++] = a[i++];
        }else{
            tmp[k++] = a[j++];
        }   
    }   
    while(i<=m){
        tmp[k++] = a[i++];
    }   
    while(j<=n){
        tmp[k++] = a[j++];

    }   

    for(i=0; i< k; i++){
        a[first + i] = tmp[i];
    }   



}

void merge_sort(int a[], int left, int right, int tmp[]){
    if(left < right)
    {   
        int mid = (left + right)/2;
        merge_sort(a,left,mid,tmp);
        merge_sort(a,mid+1,right,tmp);
        merge_array(a,left,mid,right,tmp);
    }   
}

int main(){

    int tmp[] = {1,2,5,7,1,0,2,345,15,-9,22,56,78,99};
    int buf[100]={0};

    int len = sizeof(tmp)/sizeof(int);
    printf("len is %d\n", len);

    merge_sort(tmp,0,len-1, buf);

    int i;
    for ( i=0; i< len; i++)
    {   
        printf("%d\n", tmp[i]);
    }   
    return 0;

}

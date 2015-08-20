#include <stdio.h>

int binary_select(int tmp[], int n, int value)
{
    int left = 0;
    int right = n-1;
    int middle;
    int ret;

    while(left <= right){
        middle= left + ((right-left)>>1);

        if(tmp[middle] < value){
            left = middle + 1;
        }   
        else if( tmp[middle] > value){
            right = middle - 1;
        }   
        else{
            printf("return %d\n", tmp[middle]);
            return tmp[middle];
        }   
    }   

    return -1; 

}

int main(){

    int tmp[] = {1,2,5,7,12,15,22,56,78,99};
    int len = sizeof(tmp)/sizeof(int);
    printf("len is %d\n", len);

    int ret = binary_select(tmp,len,25);
    if (ret == -1){
        printf("not found\n");
    }else{
        printf("find %d\n", ret);
    }   
    return 0;

}

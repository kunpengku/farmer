#include <stdio.h>

int select_sort(int tmp[], int len)
{

    int i,j;
    for( i = 0; i < len-1; i++){
        int min = i;
        for (j=i+1; j < len; j++){
            if(tmp[j] < tmp[min]){
                min = j;
            
            }   
        }   

        if (min != i){ 
            int t  = tmp[min];
            tmp[min] = tmp[i];
            tmp[i] = t;

        }   
    
    }   


}

int main(){

    int tmp[] = {1,2,5,7,1,0,2,345,15,22,56,78,99};
    int len = sizeof(tmp)/sizeof(int);
    printf("len is %d\n", len);

    int ret = select_sort(tmp,len);
    int i;
    for ( i=0; i< len; i++)
    {   
        printf("%d\n", tmp[i]);
    }   
    return 0;

}

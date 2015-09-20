#include <iostream>

typedef struct heap HEAP;
//
struct heap
{
    int arr[100];
    int size;
};


//将数字num 插入 最小堆
//游标 比 位置 小一
void insert(HEAP *h, int num)
{

    int sz = h->size;
    h->size++;

    while( sz >0 ){
        if(num > h->arr[(sz-1)/2]){
            h->arr[sz] = num;
            return;
        }else{
            h->arr[sz] = h->arr[(sz-1)/2]; 
            sz = (sz-1)/2;
        }   
    }   

    h->arr[0] = num;

}




void c_delete(HEAP *h) 
{
    h->size--;
    h->arr[0] = h->arr[h->size];
    h->arr[h->size] = 0;

    int i=1;
    int cv = h->arr[0];

    while(i<h->size){
        if(cv < h->arr[i] && cv < h->arr[i+1]){
            return ;
        }   

        if(h->arr[i] > h->arr[i+1])
            i++;
        else{
            h->arr[(i-1)/2] = h->arr[i];
            h->arr[i] = cv;
            i = i*2 +1;
        }
    }
}


int main()
{
    return 0;
}

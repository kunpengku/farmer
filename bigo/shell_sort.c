#include <stdio.h>
//  n,  (nlogn)^2
void shell_sort(int a[], int len)
{
    int j,gap;
    for(gap=len/2; gap>0; gap /= 2)
    {   
        for(j=gap; j<len;j++)
        {   
            if(a[j] < a[j-gap])
            {   
                int tmp = a[j];
                int k=j-gap;
                while(k>=0 && a[k]>tmp)
                {   
                    a[k+gap] = a[k];
                    k -= gap;
                }   

                a[k+gap] = tmp;
            }   
        }   
    }   
}

int main()
{
    int a[] = {23,4,5,0,23,4,5,-8,329,43,2432,-2};
    int len = sizeof(a)/sizeof(int);
    int i;

    shell_sort(a, len);
    for(i=0;i<len;i++)
        printf("%d\n",a[i]);

}

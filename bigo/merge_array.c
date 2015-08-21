#include <stdio.h>

void merge_array(int a[], int lena, int b[], int lenb, int c[])
{
	int i ,j,k;
	i=j=k=0;
	while(i< lena && j < lenb){
		if(a[i] < b[j]){
			c[k++] = a[i++];
			
		}else{
			c[k++] = b[j++];
		}
	}
	
	while(i < lena){
		c[k++] = a[i++];
	}
	
	while(j<lenb){
		c[k++] = b[j++];
	}
	
}

int main(int argc, char *argv[]) {
	int a[] = {1,2,4,6,8,99};
	int lena = sizeof(a)/sizeof(int);
	
	int b[] = {-20,-5,1,4,20,50};
	int lenb = sizeof(b)/sizeof(int);
	
	int c[30] = {0};
	merge_array(a,lena,b, lenb, c);
	
	int i=0;
	for(; i<lena+lenb; i++){
		printf("%d\n", c[i]);
	}
}
  
  

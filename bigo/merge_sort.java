package algorithm;

public class Merge {
	
	static void merge(int [] arr, int left, int mid ,int right){
		
		int [] tmp = new int[arr.length];
		int k=0;
		int i=left, j=mid;
		int m=mid+1, n=right;
		
		while(i<=j && m<=n){
			if(arr[i] < arr[m]){
				tmp[k++] = arr[i++];
			}else{
				tmp[k++] = arr[m++];
			}
		}
		
		while(i<=j){
			tmp[k++] = arr[i++];
		}
		
		while(m<=n){
			tmp[k++] = arr[m++];
		}
		
		for(int x=0;x<k;x++){
			arr[x+left] = tmp[x];
		}
	}
	
	static void mergeSort(int [] tmp,int left, int right){

		if(left < right){
			int mid = left + (right-left)/2;
			
			mergeSort(tmp, left, mid);
			mergeSort(tmp, mid+1, right);
		
			merge(tmp,left,mid,right);
		
		}
		
		
	}
	
	public static void main(String[] args) {
	
		int [] tmp = {7,6,5,4,3,2,1,10,9,8};
		int  length = tmp.length-1;
		
		mergeSort(tmp,0, length);
		
		for (int i=0; i < tmp.length; i++){
			System.out.println(tmp[i]);
		}
	}
}

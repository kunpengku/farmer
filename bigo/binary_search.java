package algorithm;

import java.util.Arrays;

public class Test {
	
	//recursion 
	static long get_gcd(long p, long q){
		if (q > p){
			long tmp = q;
			q=p;
			p=tmp;
		}
		
		if (q==0){
			return p;
		}
		
		long leav = p % q;
		return get_gcd(leav, q);
		
	}
	
	 long get_gcd2(long p, long q){
		
		long r =0;
		if (q > p){
			long tmp = q;
			q=p;
			p=tmp;
		}
		
		
		if (q==0){
			return p;
		}
		
		
		while(q != 0){
			r = p%q;
			p=q;
			q=r;
		}
		
		return p;
		
	
		
	}
	
	static boolean isPrime(int p){
		if (p < 2){
			return true;
		}
		for(int i=2; i*i <= p;i++){
			if(p%i == 0){
				return false;
			}
		}
		return true;
	}
	 
	static int rank(int [] list, int key){
		int left = 0;
		int right = list.length-1;

		while(left <= right){
			
			int mid = left + (right - left)/2;
			
			if(list[mid] == key){
				return mid;
			}else if(key < list[mid]){
				right = mid - 1;
			}else if(key > list[mid]){
				left = mid + 1;
			}
		}
		
		return -1;
	
	}
	
	public static void main(String[] args) {
		
		int [] whitelist = {1,3,50,99,13};
		Arrays.sort(whitelist);
		

		int key = 99;
		int ret = rank(whitelist, key);
		
		System.out.println(ret);
		
		
	}
}

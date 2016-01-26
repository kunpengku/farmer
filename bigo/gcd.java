package algorithm;

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
	
	static long get_gcd2(long p, long q){
		
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
	
	public static void main(String[] args) {
		long a = 319;
		long b = 377;
		
		long ret = get_gcd(b,a);
		System.out.println(ret);
		
		long ret2 = get_gcd2(b,a);
		System.out.println(ret2);
	}
}

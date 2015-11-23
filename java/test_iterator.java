public class Main {
	public static void main(String args[]){
		Set<Integer> s1 = new HashSet<Integer>();
		s1.add(1);
		s1.add(4);
		s1.add(7);
		s1.add(7);
		System.out.println(s1);
		
		Iterator i = s1.iterator();
		while(i.hasNext()){
			System.out.println(i.next());
		}
		
		
	}
	
}

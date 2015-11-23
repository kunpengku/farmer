	public static void main(String args[]){
		int [] from = {1,3,5,7,9};
		int to[] = new int[5];
		
		System.arraycopy(from, 0, to, 1, 3);
		for (int i=0;i<5;i++){
			System.out.println(to[i]);
		}
	}

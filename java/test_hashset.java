    public static void main(String[] args) {
        HashSet<Integer> filters = new HashSet<Integer>();
        
        if (!filters.contains(1)){
        	filters.add(1);
        }
        filters.add(2);
        filters.add(3);
        filters.add(3);
        
        System.out.println(filters);
    	
    }

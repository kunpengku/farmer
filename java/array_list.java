       
       
       ArrayList es_type = new ArrayList();
        if(res_type == null){
            es_type.add("courseware");
            es_type.add("exercise");
            es_type.add("clip");
        }else if(res_type.equals("1")){
            es_type.add("courseware");
        }else if(res_type.equals("2")){
            es_type.add("exercise");
        }else if(res_type.equals("3")){
            es_type.add("clip");
        }else if(res_type.equals("4")){
            es_type.add("clip");
        }else if(res_type.equals("5")){
            es_type.add("clip");
        }else if(res_type.equals("6")){
            es_type.add("clip");
        }
        
        
        ====
        ArrayList => String []
        String [] t = (String [])es_type.toArray(new String[0]);

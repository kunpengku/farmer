       
       ====
       初始化ArrayList
       ArrayList es_type = new ArrayList();
       添加元素
       es_type.add("courseware");
       es_type.add("exercise");
       es_type.add("clip");
       
        
        
        ====
        ArrayList 转换数组 String []
        方法1
        String [] t = (String [])es_type.toArray(new String[0]);

        方法2
        String [] indice = new String[es_type.size()];
        int i=0;
        for (String estype:es_type)
        {
            indice[i++] = "teacher-center-"+estype;
        }

        ====

        try{
            print $row['cnt'];
            throw new Exception('abccc');
        }catch( Exception $e){
            print $e->getMessage();
        } 

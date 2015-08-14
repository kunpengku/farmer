      $date = 20150810
      $year = (int)substr($date,0,4);
      $month = (int)substr($date,4,2);
      $day = (int)substr($date,6,2);
      echo "$year,$month,$day";
      

      $timestamp = mktime(0,0,0,$month,$day,$year);
      $end_timestamp = $timestamp + (24*3600);
      
      $start = date("Y-m-d H:i:s",$timestamp);
      $end = date("Y-m-d H:i:s",$end_timestamp);
      echo $start . "\n"; 
      echo $end ;

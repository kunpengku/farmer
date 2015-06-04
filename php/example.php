
    # php下载
    public function download()
    {    
        $url = urldecode( $this->input->get_post('url'));
        header("Location: $url");
    }    

    #输出json
    header("Content-type: text/json");
    echo json_encode($obj);
    
    #打印日志函数
    function LogRecorder($log, $FileName)
    {        
        $log = sprintf("%s %s\n", date('Y-m-d H:i:s'), $log);
        file_put_contents($FileName, $log, FILE_APPEND);
    }

    public function some_statis()
    {    
        $fr = $this->input->get_post('fr'); 
        $date = $this->input->get_post('date'); 
        $sign_in = $this->input->get_post('sign');  
        $valid_channel = array('14921', '15019'); 

        if (!in_array($fr, $valid_channel)){
            exit( '{"error_code":101, "error_msg":"错误"}' );
        }    
        $key = "dKl";
        $str = urlencode($fr).urlencode($date).$key;
        $this->LogRecorder($str, $this->log);

        $sign = strtolower(md5($str));
        if ($sign != $sign_in)
        {    
            exit( '{"error_code":"100","error_msg":"错误"}' );
        }    

        $data = array();

        $sql = "select * from  mcp'";
        $ret = mysql_query($sql , $this->fr_con);
        while($row = mysql_fetch_array($ret)){
            $line = array();
            $line['login_user'] = $row['login_user'];
            $data[] = $line;
        }    
        $output = array();
        $output['error_code'] = 0; 
        $output['error_msg'] = '成功';
        $output['data'] = $data;

        header("Content-type: text/json");
        echo json_encode($output);
    }  

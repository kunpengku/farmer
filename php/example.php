
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

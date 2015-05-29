
    # php下载
    public function download()
    {    
        $url = urldecode( $this->input->get_post('url'));
        header("Location: $url");
    }    

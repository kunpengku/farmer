    function hex2bin($hexData) 
    {
        $binData = "";
        for($i = 0; $i < strlen ( $hexData ); $i += 2) { 
        $binData .= chr ( hexdec ( substr ( $hexData, $i, 2 ) ) );
        }       
        return $binData;
    }       
    
    function cryptare($text, $key, $crypt) 
    { 
        $text = $this->hex2bin($text);
        $encrypted_data=""; 
        $td = mcrypt_module_open('des', '', 'ecb', ''); 
                
        $iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td), MCRYPT_DEV_RANDOM); 
        mcrypt_generic_init($td, $key, $iv); 

        if($crypt) 
        {       
        $encrypted_data = mcrypt_generic($td, $text); 
        print $encrypted_data ;
        }       
        else    
        {       
        $encrypted_data = mdecrypt_generic($td, $text); 
        }       

        mcrypt_generic_deinit($td); 
        mcrypt_module_close($td); 

        return $encrypted_data; 
    }

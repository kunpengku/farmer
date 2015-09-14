class AES {
    public static function encrypt($key, $plain)
    {   
        /* 打开加密算法和模式 */
        $td = mcrypt_module_open('rijndael-128', '', 'ecb', '');

        /* 创建初始向量 */
        $iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td), MCRYPT_RAND);

        /* 初始化解密模块 */
        mcrypt_generic_init($td, $key, $iv);

        /* 加密数据 */
        $encrypted = mcrypt_generic($td, $plain);

        /* 结束加密，执行清理工作，并且关闭模块 */
        mcrypt_generic_deinit($td);
        mcrypt_module_close($td);

        return base64_encode($encrypted);
    }   

    public static function decrypt($key, $encrypted)
    {   
        /* 打开加密算法和模式 */
        $td = mcrypt_module_open('rijndael-128', '', 'ecb', '');

        /* 创建初始向量 */
        $iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td), MCRYPT_RAND);

        /* 初始化解密模块 */
        mcrypt_generic_init($td, $key, $iv);

        /* 解密数据 */
        $decrypted = mdecrypt_generic($td, base64_decode($encrypted));

        /* 结束解密，执行清理工作，并且关闭模块 */
        mcrypt_generic_deinit($td);
        mcrypt_module_close($td);

        return $decrypted;
    }   
};

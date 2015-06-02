  #php curl GET请求示例
  $ch = curl_init();
  $url = 'http://10.10.0.1:8080/test';
  
  $url = "$url?req={\"orderId\":\"$orderid\"}";
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_HEADER, 0);
  $output = curl_exec($ch);
  curl_close($ch);
  $out_content = json_decode($output);
  $ret = $out_content->retcode;
  
  
<span style="font-size:18px;">$url = "http://www.xxxx.com?user=111";  
$post_data = "somedata";  
  
$ch = curl_init();  
  
curl_setopt($ch, CURLOPT_URL, $url);  
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);  
curl_setopt($ch, CURLOPT_HEADER, 0);  
curl_setopt($ch , CURLOPT_POST , 1 ) ;  
curl_setopt($ch , CURLOPT_POSTFIELDS , $post_data ) ;  
  
$out = curl_exec($ch);  
curl_close($ch);  
$obj = json_decode($out);  
print $obj;  
</span>

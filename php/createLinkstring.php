<?php
function createLinkstring($para) {
    $arg  = ""; 
    while (list ($key, $val) = each ($para)) {
        $arg.=$key."=".$val."&";
    }   
    //去掉最后一个&字符
    $arg = substr($arg,0,count($arg)-2);
    
    //如果存在转义字符，那么去掉转义
    if(get_magic_quotes_gpc())
    {   
        $arg = stripslashes($arg);
    }   
        
    return $arg;
}

function createLinkstring02($valueMap){
    $i = 0;
    foreach($valueMap as $key=>$value)
    {
        if($key != "sign" )
        {   
           $content .= ($i == 0 ? '' : '&').$key.'='.$value;
        }   
        $i++;
    }
    return $content;
}

$in['name'] = 'fupeng';
$in['age'] = 25;
$in['guxiang'] = 'shanxi';

print_r($in);

print createLinkstring($in);
print "\n";
print createLinkstring02($in);



?>

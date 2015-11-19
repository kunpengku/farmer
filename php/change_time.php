



function str_to_timestamp($str)
{

    date_default_timezone_set("prc");  

    $time_arr = strtotime($str);
    $timestamp = date($time_arr);
    return $timestamp;
}

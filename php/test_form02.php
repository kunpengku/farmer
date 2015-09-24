<?php

$date1 = $_POST['date'];
$date = str_replace('-','', $date1);
$appid = $_POST['appid'];

if (empty($appid))
{
    $today = date("Y-m-d");
    $appid = 102;
    $date = str_replace('-','', $today);
    print '<form name="form" method="post" action="stat.php">';
    print 'appid <input type="text" name="appid" value="102"> <br />';
    print '日期 <input type="date" name="date" value="'. $today .'"><br />';
    print '<input type="submit">';
    print '</form>';
    echo $b->checkout($date,$appid);
}

else{

    print '<form name="form" method="post" action="stat.php">';
    print 'appid <input type="text" name="appid" value="'.$appid.'"> <br />';
    print '日期 <input type="date" name="date" value="'. $date1.'"><br />';
    print '<input type="submit">';
    print '</form>';
    echo $b->checkout($date,$appid);
}

?>

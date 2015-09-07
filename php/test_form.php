<?php
print '<form name="form" method="post" action="tongji_F.php">';
print 'appid <input type="text" name="appid" value="1002">  <br />';
print '日期 <input type="date" name="date"><br />';
print '<input type="submit">';
print '</form>';

#
$date1 = $_POST['date'];
$date = str_replace('-','', $date1);
$appid = $_POST['appid'];
echo $b->checkout($date,$appid);


?>

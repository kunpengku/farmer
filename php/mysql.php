#连接
$this->con6= mysql_connect("10.10.1.1:3306","work","123456");
if (!$this->con6){
    die('Could not connect: ' . mysql_error());
}        
mysql_query("set names utf8");

#fetchone
$query = "select id from class limit 1"; 
$result = mysql_query($query, $con);
$row = mysql_fetch_array($result);
$id = $row["id"];

#fetchall
$query = "select id from class limit 10";
$result = mysql_query($query, $con);
while($row = mysql_fetch_array($result))
{
  $id_array[] = $row["id"];
}

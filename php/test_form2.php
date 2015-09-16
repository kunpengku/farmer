if( isset($_POST['submit']) && $_POST['submit'] == '提交' )
{
    $uname = $_POST['username'];
    $b = new tongji();
    $b->user_order($uname);

}


print '<form name="form" method="post" >';
print 'username:<input type="text" name="username" ><br />';
print '<input type="submit" name="submit" value="提交" >';
print '</form>';

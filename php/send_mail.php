#用PHP 发邮件， 因为这个可以发送 大附件。

<?php

require_once('/home/work/www/source/PHPMailer-master/class.phpmailer.php');

$mail_to = array('fupeng@baidu-mgame.com');
$mail_cc = array('fupeng2@baidu-mgame.com');


$date = date('Y-m-d', strtotime("-1 day"));
$date_format2 = date('Ymd', strtotime("-1 day"));
#$date = date('Y-m-d', strtotime("-2 day"));
#date_format2 = date('Ymd', strtotime("-2 day"));

main($date, $mail_to, $mail_cc);

function main($date, $mail_to, $mail_cc)
{
    $file_path = "/home/work/all_cannt_download.txt";
    send_mail($date, $mail_to, $mail_cc, $file_path);
}

function send_mail($date, $mail_to, $mail_cc, $file_path, $file_path2)
{
    $subject = "oe" . $date;
    $body = "Hi all:\r\n\t。\r\n";

    $mail = new PHPMailer();

    $mail->IsSMTP();
    $mail->SMTPDebug = 0;
    $mail->SMTPAuth = true;
    $mail->SMTPSecure = "tls";

    $mail->CharSet = "utf-8";
    $mail->Encoding = "base64";
    $mail->MessageID = time();

    $mail->Host = 'email.xxx.com';
    $mail->Port = 587;
    $mail->Username = 'info';
    $mail->Password = 'Cb5D';
    $mail->From = 'info@xxxgame.com';
    $mail->FromName = ''; 

    if (isset($mail_to))
    {   
        foreach ($mail_to as $elem)
        {   
            $mail->AddAddress($elem);
        }   
    }   
    if (isset($mail_cc))
    {   
        foreach ($mail_cc as $elem)
        {   
            $mail->AddCC($elem);
        }   
    }

    $mail->Subject = $subject;
    $mail->Body = $body;
    $mail->AddAttachment($file_path);


    if(!$mail->Send())
    {
        $msg = "send mail error:" . $mail->ErrorInfo;
    }
    else
    {
        $msg = "send mail success";
    }
}

?>

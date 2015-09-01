#!/bin/bash
#set -x

REMOTE_IP="10.10.1.60"
INSTALL_PATH="/home/work/install"
LOCAL_PATH="/home/work"

function remote_cp()
{
        expect<<EOF
        set timeout 30
        spawn scp  $4 $1 $2
        expect "*assword:"
        send "$3\r"
        expect eof
EOF
}


remote_cp $REMOTE_IP:$INSTALL_PATH  $LOCAL_PATH  chinglemon2992825 -r
# scp -r 10.254.166.60:/home/work/install  /home/work

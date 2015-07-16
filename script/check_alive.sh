#!/bin/bash

RC_PATH="/home/work/fupeng/batch_tool"

function check_rc()
{
    rc_info=$(ps -aef | grep "web_game_sign.py" | grep -v "grep" | grep -v "tail" | grep -v "vi" | grep -v "gdb" )
    if [[ "$rc_info" = "" ]]
    then
        cd ${RC_PATH}
        sh start_websing.sh
        ip=`/sbin/ifconfig eth0 | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}'`
        hostname=`hostname`
    fi
}

while [ 0 ]
do
  check_rc
  sleep 1
done

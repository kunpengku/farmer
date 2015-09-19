#!/bin/bash
STAT_OK=0
STAT_WARNING=1
STAT_CRITICAL=2
STAT_UNKNOWN=3

total_mem=`free -m |awk 'NR==2{print $2}'`
used_mem=`free -m |awk 'NR==3{print $3}'` #取的是系统真正用掉的内存
free_mem=`free -m |awk 'NR==3{print $4}'` #取的是free+cache的内存
use_per=`echo "scale=2;$used_mem/$total_mem"|bc|sed 's/^.//g'`

help() {
        echo "USAGE:`basename $0` [-w] <used percent> [-c] <used percent> [-h]"
        exit -1
}

while getopts ":w:c:h" opt
do
        case $opt in
                w)      warning=$OPTARG
                        ;;
                c)      critical=$OPTARG
                        ;;
                h)      help
                        ;;
                ?)      unkown=$OPTARG
                        echo "error,plase check for help,USAGE:./`basename $0` -h"
                        exit $STAT_UNKNOWN
                        ;;
        esac
done


if [[ $use_per -lt $warning ]]
then
        echo "OK - total:$total_mem MB,used:$used_mem MB,free:$free_mem MB | total_mem=$total_mem u
sed_mem=$used_mem free_mem=$free_mem"
        exit $STAT_OK

elif [[ $use_per -ge $warning ]] && [[ $use_per -lt $critical ]]
then
                 echo "WARNING - total:$total_mem MB,used:$used_mem MB,free:$free_mem MB | total_me
m=$total_mem used_mem=$used_mem free_mem=$free_mem"
                 exit $STAT_WARNING
else
                 echo "CRITICAL - total:$total_mem MB,used:$used_mem MB,free:$free_mem MB | total_m
em=$total_mem used_mem=$used_mem free_mem=$free_mem"
                 exit $STAT_CRITICAL
fi


#/usr/local/nagios/libexec/check_mem.sh   -w 90 -c 90

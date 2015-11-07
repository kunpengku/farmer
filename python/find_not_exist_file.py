#!/usr/local/python/bin/python

# coding:utf-8

import os
import MySQLdb
import json


def parse_list(alist,oldid):
    for item in alist:
        if isinstance(item, dict):
            parse_dic(item,oldid)

def parse_dic(adict,oldid):
    for key,val in adict.items():
        if isinstance(val, list) :
            parse_list(val,oldid)
    

        if key == 'type' and val == 'image':
            #print key, type(val),val
            file_path = '/image' + adict['value']
    
            if not os.path.exists(file_path):
                print 'not exist',oldid,file_path
                f.write('%s,%s\n' % ( oldid,file_path))


def check_exist(result,f):

    #print result
    try:
        content = json.loads(result['json'])
    except:
        return
    oldid = result['oldid']

    try:
        parse_dic(content,oldid)
    except:
        print  oldid
        raise

            
#这个程序从数据库中检查所有的记录， 把其中的图片文件，不存在的记录找出来 ，写在一个文件中。
if __name__ == '__main__':

    db_handle = MySQLdb.connect(host='12.1.14.2',user = 'test', passwd = '123456',  db = 'test',port = 3306, charset = 'utf8')
    f = open('not_exist_id.txt', 'w')


    #有100W条记录，分100次查询
    for i in range(100):
        t_id = i*10000
        end = t_id+10000

        sql = "select old,json from person where id >= %s and id < %s" % (t_id, end)

        print (sql)

        cur = db_handle.cursor( MySQLdb.cursors.DictCursor )
        cur.execute( sql )
        result = cur.fetchall()
        cur.close()
        for row in result:

            check_exist(row,f)


    f.close()


    db_handle.close()


           

  

#!/usr/local/bin/python
#  coding:utf-8 
import MySQLdb

db_handle = MySQLdb.connect(host = '10.10.1.1', user = 'work', passwd = '111111',  db = 'test',port = 3306, charset = 'utf8')      

    
sql = "insert into person2  (`number`,`hav`,`status`) values (%s,'0','0')" % num
print (sql)
cur = db_handle.cursor( MySQLdb.cursors.DictCursor )
cur.execute( sql )
cur.close()
db_handle.commit()



    
db_handle.close()

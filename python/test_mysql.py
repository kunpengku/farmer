#!/usr/local/bin/python
#  coding:utf-8 
import MySQLdb
import sys 
reload(sys)
sys.setdefaultencoding('utf-8')

db_handle = MySQLdb.connect(host = '10.10.1.1', user = 'work', passwd = '111111',  db = 'test',port = 3306, charset = 'utf8')      

    
sql = "insert into person2  (`number`,`hav`,`status`) values (%s,'0','0')" % num
print (sql)
cur = db_handle.cursor( MySQLdb.cursors.DictCursor )
cur.execute( sql )
cur.close()
db_handle.commit()

chapter_name = MySQLdb.escape_string( self.chapter_name(row['chapter_id']) )



    
db_handle.close()

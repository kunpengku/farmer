# coding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf8')

f=open('test.xls','w')

msg = '中国'
msg = msg.encode('gb2312')

f.write('%s\t%s\n' % (1,msg))

f.close()

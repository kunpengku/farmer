#!/usr/bin/python

import threading

import time

class Producer(threading.Thread):

    def __init__(self, t_name):
        threading.Thread.__init__(self, name=t_name)

    def run(self):

        global x
        con.acquire()
        print 'Producer get the con'
        if x > 0:
            con.wait()
        else:
            for i in range(5):
                x=x+1
                print "producing..." + str(x)
            con.notify()
            time.sleep(2)
        print x,'in producer'
        con.release()
        
  
class Consumer(threading.Thread):  
  
    def __init__(self, t_name):  
        threading.Thread.__init__(self, name=t_name)  
  
    def run(self):  
        global x  
        con.acquire()  
        print 'Consumer get the con, x=',x
        if x == 0:  
            print 'consumer wait'  
            con.wait()
        else:
            for i in range(5):
                x=x-1
                print "consuming..." + str(x)
            con.notify()
        print x ,'in consumer'
        con.release()



con = threading.Condition()
x=0
print 'x=',x
print 'start consumer'
c=Consumer('consumer')
print 'start producer'
p=Producer('producer')

p.start()
time.sleep(3)
c.start()

p.join()
c.join()

print x

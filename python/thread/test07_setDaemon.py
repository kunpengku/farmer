# encoding: UTF-8
import threading
import time

def func():
    print 'in thread sleep 1'
    time.sleep(1)
    print 'in thread sleep 1'
    time.sleep(1)
    print 'in thread sleep 1'
    time.sleep(1)
    print 'in thread sleep 1'
    time.sleep(1)
    print 'in thread sleep 1'
    time.sleep(1)


t1 = threading.Thread(target=func)
t1.setDaemon(True)
t1.start()

print 'main thread sleep 2'
time.sleep(2)

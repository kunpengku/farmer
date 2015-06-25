# Multiprocessing with Pipe
# Written by Vamei

import multiprocessing as mul 
import time

def proc1(pipe):
    time.sleep(1)
    pipe.send('hello1111')
    print('proc1 rec:',pipe.recv())

def proc2(pipe):
    print('proc2 rec:',pipe.recv())
    time.sleep(3)
    pipe.send('hello2222, too')

# Build a pipe
pipe = mul.Pipe()

# Pass an end of the pipe to process 1
p1   = mul.Process(target=proc1, args=(pipe[1],))
# Pass the other end of the pipe to process 2
p2   = mul.Process(target=proc2, args=(pipe[0],))
print '1' 
p1.start()
print '2' 
p2.start()
print '3' 
p1.join()
p2.join()

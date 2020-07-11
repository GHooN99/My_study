from sys import stdin
from collections import deque

n=int(stdin.readline())
op=[]
queue = deque()
for i in range(n):
    op = stdin.readline().split()
    if op[0]=="push":
        queue.appendleft(int(op[1]))
    elif op[0]=="pop":
        if len(queue)==0:
            print(-1)
        else:
            print(queue.pop())
    elif op[0]=="size":
        print(len(queue))
    elif op[0]=="empty":
        if len(queue)==0:
            print(1)
        else:
            print(0)
    elif op[0]=="front":
        if len(queue)==0:
            print(-1)
        else:
            print(queue[-1])
    elif op[0]=="back":
        if len(queue)==0:
            print(-1)
        else: 
            print(queue[0])

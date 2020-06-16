from sys import stdin
from collections import deque
n = int(stdin.readline())
deq = deque()
for i in range(n):
    op = stdin.readline().rstrip().split()
    if op[0] == "push_back":
        deq.append(int(op[1]))
    elif op[0] == "push_front":
        deq.appendleft(int(op[1]))
    elif op[0] == "pop_back":
        if len(deq)==0:
            print(-1)
        else:
            print(deq.pop())
    elif op[0] == "pop_front":
        if len(deq)==0:
            print(-1)
        else:
            print(deq.popleft())        
    elif op[0] == "size":
        print(len(deq))
    elif op[0] == "empty":
        if len(deq)==0:
            print(1)
        else:
            print(0)
    elif op[0] == "front":
        if len(deq)==0:
            print(-1)
        else:
            print(deq[0])
    elif op[0] == "back":
        if len(deq)==0:
            print(-1)
        else:
            print(deq[-1])        



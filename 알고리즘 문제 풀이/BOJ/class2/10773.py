from sys import stdin 
from collections import deque

n = int(stdin.readline())
stack = deque()
for i in range(n):
    k = int(stdin.readline())
    if k==0:
        stack.pop()
    else:
        stack.append(k)
print(sum(stack))   

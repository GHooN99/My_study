from sys import stdin
from collections import deque

n=int(stdin.readline())

a = n//3
b = n//5
arr=deque()
for i in range(a,-1,-1):
    for j in range(0,b+1):
        if 3*i+5*j==n:
            arr.append(i+j)

if len(arr)==0:
    print(-1)
else:
    print(min(arr))
    
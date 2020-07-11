from sys import stdin
from collections import deque

valid =True
n=int(stdin.readline())
arr = deque()
stack = deque(range(1,n+1))
prev = 0

ans =deque()

for i in range(n):
    num =int(stdin.readline())

    if num >prev:
        if len(stack)!=0:
            while True:
                if len(stack)==0:
                    valid=False
                    break
                item = stack.popleft()
                arr.appendleft(item)
                ans.append('+')
                
                if item == num:
                    break
            prev = arr.popleft()
            ans.append('-')
        else:
            valid=False
            break
    
    else:
        while True:
            if len(arr)==0:
                valid=False
                break
            item = arr.popleft()
            ans.append('-')
            if item == num:
                prev = item
                break
    if not valid:
        break
if valid:
    for i in ans:
        print(i)
else:
    print("NO")
    

from sys import stdin
from collections import deque

def isvalid(str):
    stack = deque()
    for i in str:
        if i=='(' or i=='[':
            stack.appendleft(i)
        elif i==')':
            if len(stack)==0:
                return False
            item = stack.popleft()
            if item != '(':
                return False
        elif i==']':
            if len(stack)==0:
                return False
            item = stack.popleft()
            if item != '[':
                return False
    
    if len(stack)==0:
        return True

    return False

while True:
    str = stdin.readline().rstrip()
    if str =='.':
        break
    else:
        if isvalid(str):
            print("yes")
        else:
            print("no")

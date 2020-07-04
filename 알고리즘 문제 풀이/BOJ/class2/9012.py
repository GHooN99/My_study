from sys import stdin
from collections import deque

def isvalid(arr):
    st = deque()
    for i in range(len(arr)):
        if arr[i]=='(':
            st.appendleft(arr[i])
        elif arr[i]==')':
            if len(st)==0:
                return False
            if st.popleft()!='(':
                return False
    
    if len(st)!=0:
        return False
    else:
        return True

n=int(stdin.readline())

for i in range(n):
    arr = stdin.readline().rstrip()
    if isvalid(arr):
        print("YES")
    else:
        print("NO")

from sys import stdin
from collections import deque,Counter
import bisect

def solution(arr,num,ptrs):
    start = 0
    end =len(arr)-1
    while True:
        if ptrs==0:
            ptr = (start+end)//2
        else:
            ptr=ptrs
        
        if end-start<0:
            return False,0
        if arr[ptr]==num:
            del arr[ptr]
            return True,ptrs
        elif arr[ptr]>num:
            end = end-1
        else:
            start = start+1


# input
n = int(stdin.readline())
arr = deque(sorted(map(int,stdin.readline().split())))
m = int(stdin.readline())
answer = deque([0]*m)
tar = deque(map(int,stdin.readline().split()))



for i,num in enumerate(tar):
    idx=0
    while True:
        check,idx = solution(arr,num,idx)
        if not check:
            break
        answer[i]+=1
# output
for i in answer:
    print(i,end=' ')




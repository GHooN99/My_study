from sys import stdin



def solution(arr,num):
    start = 0
    end =len(arr)-1
    while True:
        ptr = (start+end)//2

        if end-start<0:
            return False,0
        if arr[ptr]==num:
            cnt=arr[start:end+1]
            return True,cnt.count(num)
        elif arr[ptr]>num:
            end = end-1
        else:
            start = start+1


# input
n = int(stdin.readline())
arr = sorted(map(int,stdin.readline().split()))
m = int(stdin.readline())
answer = [0]*m
tar = list(map(int,stdin.readline().split()))



for i,num in enumerate(tar):
    check,cnt = solution(arr,num)
    if check:
        answer[i]+=cnt

# output
for i in answer:
    print(i,end=' ')




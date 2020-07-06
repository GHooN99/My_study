from sys import stdin

def calMoney(arr):
    # 같은눈 4개
    if len(set(arr))==1:
        return arr[0]*5000+50000

    #같은눈 3 /1 or 2/2
    if len(set(arr))==2:
        if arr[1]==arr[2]:   
            return arr[1]*1000+10000 # 3/1
        return (arr[1]+arr[2])*500+2000
    # 같은거 한쌍 
    for i in range(3):
        if arr[i]==arr[i+1]:
            return arr[i]*100+1000
    # 모두다름  맨 마지막이 최대값
    return arr[-1]*100


n = int(stdin.readline())

money =[]
for i in range(n):
    arr = list(map(int,stdin.readline().split()))
    money.append(calMoney(sorted(arr)))

print(max(money))
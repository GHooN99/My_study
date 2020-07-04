from sys import stdin

n , k =map(int,stdin.readline().split())
arr = list(range(1,n+1))
ans = []
while len(arr)!=0:
    for i in range(k-1):
        arr.append(arr.pop(0))
    ans.append(arr.pop(0))

print('<'+str(ans)[1:-1]+'>')


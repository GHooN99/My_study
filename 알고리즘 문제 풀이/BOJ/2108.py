from sys import stdin

n=int(stdin.readline())
lis=[]
cnt =[0]*8001
sum_s = 0

for i in range(n):
    s = int(stdin.readline())
    lis.append(s)
    cnt[s]+=1
    sum_s += s


lis.sort()

print(int(round(sum_s/n,0)))

print(lis[len(lis)//2])

max_cnt = max(cnt)
number=[]
if cnt.count(max_cnt) == 1:
    ans = cnt.index(max_cnt)
    if ans>4000:
        ans=ans-8001
    print(ans)
else:
    for i in range(len(cnt)):
        if max_cnt == cnt[i] :
            if i>4000:
                number.append(i-8001)
            else:
                number.append(i)
    #print(number)
    number=list(set(number))
    number.sort()
    print(number[1])

print(max(lis)-min(lis))



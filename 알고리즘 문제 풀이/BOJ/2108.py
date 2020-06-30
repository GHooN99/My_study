from sys import stdin

def find(s):
    cnt =[]
    result=[]
    for i in s:
        cnt.append(s.count(i))
    max_cnt = max(cnt)
    for i in range(len(cnt)):
        if cnt[i]==max_cnt:
            result.append(s[i])

    result=list(set(result))
    if len(result)==1:
        return result[0]
    else:
        result.sort()
        return result[1]
        




# 1 2 3 3 4 5 5 
n=int(stdin.readline())
lis=[]
cnt =[0]*8000
sum_s = 0
max_s = -5000
min_s = 5000
for i in range(n):
    s= int(stdin.readline())
    lis.append(s)
    cnt[s]+=1
    sum_s += s
    if max_s < s:
        max_s = s
    if min_s > i:
        min_s = s
    
s.sort()



print(int(round(sum_s/n,0)))
print(s[n//2])
print(find(s))
print(max_s-min_s)



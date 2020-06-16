from sys import stdin

n,m = map(int,stdin.readline().split())
s = list(map(int,stdin.readline().split()))
prev = 0
for i in range(0,n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            if s[i]+s[j]+s[k] <=m:
                if prev < s[i]+s[j]+s[k]:
                    prev = s[i]+s[j]+s[k]
print(prev)


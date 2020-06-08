n = [0]*42
for i in range(10):
    a = int(input())
    n[a%42]+=1
cnt = 0
for i in n:
    if i != 0:
        cnt+=1
print(cnt)

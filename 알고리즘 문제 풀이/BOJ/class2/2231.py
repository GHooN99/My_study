from sys import stdin

n = stdin.readline().rstrip()
flag = False
d = len(n)
n = int(n)
r = n//10**(d-1)
for i in range((r-1)*10**(d-1),n+1):
    s = list(str(i))
    s = list(map(int,s))
    if n == i+sum(s):
        print(i)
        flag = True
        break
if not flag:
    print(0)



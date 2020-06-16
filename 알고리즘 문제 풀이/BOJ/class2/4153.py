from sys import stdin

while(True):
    s = list(map(int,stdin.readline().split()))
    s.sort()
    if s[0] ==0 and s[1] == 0 and s[2]==0:
        break
    if s[0]**2+s[1]**2 == s[2]**2:
        print("right")
    else:
        print("wrong")
from sys import stdin 


def isPrime(n):
    if n>2 and n%2 == 1:
        for i in range(3,n,2):
            if n%i == 0 :
                return False
        return True
    elif n==2:
        return True
    else:
        return False 


n = int(stdin.readline())
num = list(map(int,stdin.readline().split()))
cnt = 0
for i in num:
    if isPrime(i):
        cnt+=1
print(cnt)
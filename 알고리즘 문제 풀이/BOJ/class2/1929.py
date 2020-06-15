from sys import stdin
import math
def isPrime(n):
    
    if n>3 and n%2==1:
        for i in range(3,int(math.sqrt(n))+1,2):
            if n%i==0:
                return False
        return True
    
    elif n==2 or n==3:
        return True
    else:
        return False
    

a,b = map(int,stdin.readline().split())

for i in range(a,b+1):
    if isPrime(i):
        print(i)
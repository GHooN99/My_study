from sys import stdin

def gcd(a,b):
    for i in range(max(a,b),1,-1):
        if a%i==0 and b%i==0:
            return i
    return 1
def lcm(a,b):
    return a*b//gcd(a,b)

a,b = map(int,stdin.readline().split())

print(gcd(a,b))
print(lcm(a,b))



import sys
 
n= int(sys.stdin.readline())
a=[sys.stdin.readline().rstrip() for i in range(n)]
a = list(set(a))
print(len(a))
for i in range(len(a)-1):
    for j in range(len(a)-1-i):
        if len(a[j])>len(a[j+1]):
            a[j],a[j+1] = a[j+1],a[j]
for i in range(len(a)-1):
    for j in range(len(a)-1-i):
        if (a[j])>len(a[j+1]):
            a[j],a[j+1] = a[j+1],a[j]

for i in a:
    print(i)
a,b = input().split()
a = int(a)
b= int(b)
s=input().split()
for i in range(a):
    s[i]=int(s[i])
    if s[i]<b:
        print(s[i],end=' ')


    

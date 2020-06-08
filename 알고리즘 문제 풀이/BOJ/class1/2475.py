s = input().split()
for i in range(5):
    s[i]=int(s[i])
    s[i] = s[i]**2
print(sum(s)%10)

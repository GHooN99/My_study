result = 1
num = [0]*10
for i in range(3):
    result *= int(input())

while result>0:
    num[result%10]+=1
    result//=10

for i in num:
    print(i)



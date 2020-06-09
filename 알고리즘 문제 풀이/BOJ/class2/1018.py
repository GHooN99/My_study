import sys

def count_num(str): 
    cnt1 = 0
    cnt2 = 0
    if str[0][0]=='W':
        for i in range(8):
            for j in range(8):
                if i%2==0 and j%2==0:
                    if str[i][j]!='W':
                        cnt1+=1
                elif i%2==0 and j%2==1:
                    if str[i][j]!='B':
                        cnt1+=1
                elif i%2==1 and j%2==0:
                    if str[i][j]!='B':
                        cnt1+=1
                else:
                    if str[i][j]!='W':
                        cnt1+=1
                           
    else:
        for i in range(8):
            for j in range(8):
                if i%2==0 and j%2==0:
                    if str[i][j]!='B':
                        cnt1+=1
                elif i%2==0 and j%2==1:
                    if str[i][j]!='W':
                        cnt1+=1
                elif i%2==1 and j%2==0:
                    if str[i][j]!='W':
                        cnt1+=1
                else:
                    if str[i][j]!='B':
                        cnt1+=1
    if str[0][0]=='W':
        for i in range(8):
            for j in range(8):
                if i%2==0 and j%2==0:
                    if str[i][j]!='B':
                        cnt2+=1
                elif i%2==0 and j%2==1:
                    if str[i][j]!='W':
                        cnt2+=1
                elif i%2==1 and j%2==0:
                    if str[i][j]!='W':
                        cnt2+=1
                else:
                    if str[i][j]!='B':
                        cnt2+=1
                           
    else:
        for i in range(8):
            for j in range(8):
                if i%2==0 and j%2==0:
                    if str[i][j]!='W':
                        cnt2+=1
                elif i%2==0 and j%2==1:
                    if str[i][j]!='B':
                        cnt2+=1
                elif i%2==1 and j%2==0:
                    if str[i][j]!='B':
                        cnt2+=1
                else:
                    if str[i][j]!='W':
                        cnt2+=1    
            
    return min(cnt1,cnt2)


a,b = map(int,sys.stdin.readline().split())
s =[sys.stdin.readline().rstrip() for i in range(a)]
cnt_arr = []
x = 0
y = 0
while True:
    new_str = []

    for i in range(0+y,8+y):
        tmp =[]
        for j in range(0+x,8+x):
            tmp.append(s[i][j])
        new_str.append(''.join(tmp))

    cnt_arr.append(count_num(new_str))
    print(new_str)
    #print(count_num(new_str))
    x+=1
    if x==b-7:
        x=0
        y+=1
        if y==a-7:
            break

print(cnt_arr)
print(min(cnt_arr))
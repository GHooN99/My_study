from sys import stdin

n = int(stdin.readline())
i=660
cnt = 0 
while(cnt<n):
    if str(i).find('666')>=0:
        cnt+=1
        if cnt == n :
            print(i)
            break
    i+=1

    


from sys import stdin

a,b,v = map(int,stdin.readline().split())

if (v-b)%(a-b)==0:  #v-b 만큼 올라가는게 맞으면 
    print((v-b)//(a-b))
else: # 안되면 1일 더 지나야함 
    print((v-b)//(a-b)+1)
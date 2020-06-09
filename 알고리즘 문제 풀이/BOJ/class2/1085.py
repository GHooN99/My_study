import sys
x,y,w,h = map(int,sys.stdin.readline().split())
print(min(map(abs,[x-w,x,y-h,y])))

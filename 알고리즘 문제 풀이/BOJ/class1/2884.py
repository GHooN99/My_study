h,m =input().split()
h = int(h)
m = int(m)
time = h * 60 + m
time = time - 45
if time < 0:
    time = time+24*60


h = time//60
m = time%60
print("%d %d"%(h,m))

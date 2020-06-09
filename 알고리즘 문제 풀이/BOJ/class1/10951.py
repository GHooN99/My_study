#read eof
while(True):
    try:
        a,b = input().split()
        a = int(a)
        b= int(b)
        print(a+b)
    except:
        break
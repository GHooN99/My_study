num = input()

''' 
if num[0] == '1':
    for i in range(1,9):
        if i!=ord(num[i-1])-ord('0'):
            print("mixed")
            break
    if i==8:
        print("ascending")

elif num[0]=='8':
    for i in range(8,0,-1):
     if i!=ord(num[8-i])-ord('0'):
        print("mixed")
        break
    if i==1:
        print("descending")
else:
    print("mixed")
'''
if num == "1 2 3 4 5 6 7 8":
    print("ascending")
elif num == '8 7 6 5 4 3 2 1':
    print("descending")
else:
    print("mixed")
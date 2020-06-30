from sys import stdin

def bSearch(arr,start,end,data):
    if start > end: # base case
        return False
    mid = (start+end)//2
    if(arr[mid] == data):
        return True
    elif(arr[mid] > data):
        end = mid -1
    else:
        start = mid +1
    return bSearch(arr,start,end,data)

n = int(stdin.readline())
a = list(map(int,stdin.readline().split()))

m = int(stdin.readline())
b = list(map(int,stdin.readline().split()))
# bsearch 
a.sort()

for i in b:
    if bSearch(a,0,len(a)-1,i):
        print(1)
    else:
        print(0)



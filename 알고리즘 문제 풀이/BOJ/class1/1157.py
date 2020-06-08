''' 
# O(n^2)
a = input()
pr = True
max_cnt = 0 
max_idx = 0

for i in range(len(a)):
     count = a.count(a[i])
     if max_cnt<count:
         max_cnt = count
         max_idx = i
     elif max_cnt == count:
         
         if a[max_idx] != a[i]:
             pr = False
             break
if pr:
    print(a[max_idx].upper())
else:
    print('?')
    
    
'''
# O(n) ?

a = input().upper()
alpha = [0]*26

for i in a:
    alpha[ord(i)-ord('A')] +=1

max_value = max(alpha)

if alpha.count(max_value)<2:
    k = alpha.index(max_value)+ord('A')
    print(chr(k))
else:
    print('?')



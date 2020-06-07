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
    
    
    
    
    

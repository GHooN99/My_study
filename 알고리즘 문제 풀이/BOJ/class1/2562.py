a = []
for i in range(9):
    a.append(int(input()))
max_val = max(a)  
print(max_val)
print(a.index(max_val)+1)
n = int(input())
score = input().split()
for i in range(n):
    score[i] = int(score[i])

M = max(score)

for i in range(n):
    score[i] = score[i]/M*100

print(sum(score)/n)
    


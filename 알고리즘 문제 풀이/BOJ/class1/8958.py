'''
def find_score(test_str):
    score = 0
    i = 0
    while(i<len(test_str)):
        cnt = 0
        if test_str[i] == 'O':
            while(test_str[i]!='X'):
                cnt += 1
                score += cnt
                i+=1
                if i==len(test_str):
                    break
            i-=1
        i+=1
    return score
'''
n = int(input())
for i in range(n):
    score = 0
    cnt = 0
    test = input()
    #print(find_score(test)) ##use func
    for j in test:
        if j =='O':
            cnt += 1 # combo bonus
            score += cnt
        else:
            cnt = 0
    print(score)

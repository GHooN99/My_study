alpha = [-1]*26
s = input()
for i in range(len(s)):
    if alpha[ord(s[i])-ord('a')] == -1:
        alpha[ord(s[i])-ord('a')]=i
for i in alpha:
    print(i,end=' ')
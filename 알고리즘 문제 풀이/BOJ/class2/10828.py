from sys import stdin

n = int(stdin.readline())

stack = []

for i in range(n):
    op = stdin.readline().rstrip().split()
    if op[0] == "push":
        stack.append(int(op[1]))
    elif op[0] == "pop":
        if len(stack)>=1:
            print(stack.pop())
        else:
            print(-1)

    elif op[0] == "size":
        print(len(stack))
    elif op[0] == "empty":
        if len(stack)>0:
            print(0)
        else:
            print(1)
    else:
        if len(stack)>0:
            print(stack[-1])
        else:
            print(-1)

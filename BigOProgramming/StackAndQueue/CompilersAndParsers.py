n = int(input())
for i in range(n):
    expression = input()
    stack = []
    count = 0
    for pos in range(len(expression)):
        if expression[pos] == '<':
            stack.append(expression[pos])
        else:
            if len(stack) > 0:
                stack.pop()
                count += 2
                if len(stack) == 0:
                    count = pos + 1
            else:
                break
    print(count)
    
    
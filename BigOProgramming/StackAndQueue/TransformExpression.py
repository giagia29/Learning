t = int(input())
stack = []
for i in range(t):
    expression = input()
    for char in expression:
        if char == '(':
            continue
        elif 97 <= ord(char) <= 122:
            print(char)
        elif 42 <= ord(char) <= 47 or ord(char) == 94:
            stack.append(char)
        else:
            value = stack.pop()
            print(value)

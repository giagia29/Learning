formula = input()
stack = []

def to_mass(value) -> int:
    m = 0
    if value == 'H':
        m += 1
    elif value == 'C':
        m += 12
    else:
        m += 16
    return m


for ch in formula:
    if ch == ')':
        sum = 0
        while stack[-1] != '(':
            sum += stack.pop()
        stack.pop()
        stack.append(sum)
    elif ch.isdigit():
        sum = stack.pop() * int(ch)
        stack.append(sum)
    elif ch.isupper():
        stack.append(to_mass(ch))
    else:
        stack.append('(')
total = 0
for i in range(len(stack)):
    total += stack[i]
print(total)
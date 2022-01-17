list_x = []
list_y = []
points = []

for i in range(8):
    x, y = map(int, input().split())
    list_x.append(x)
    list_y.append(y)
    points.append([x, y])
    
list_x.sort()
list_y.sort()

unique_x = [list_x[0]]
unique_y = [list_y[0]]
for i in range(1, 8):
    if list_x[i] != list_x[i-1]:
        unique_x.append(list_x[i])
for i in range(1, 8):
    if list_y[i] != list_y[i-1]:
        unique_y.append(list_y[i])

if len(unique_x) != 3 or len(unique_y) != 3:
    print('ugly')
    exit(0)

for i in range(3):
    for j in range(3):
        if i == 1 and j == 1:
            continue
        ptr = [unique_x[i], unique_y[j]]
        if ptr not in points:
            print('ugly')
            exit(0)
print('respectable')

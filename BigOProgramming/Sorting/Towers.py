# n = int(input())
# l = list(map(int, input().split()))
# l.sort()
# sum = 0
# length_tower = [0] * 1001
# for i in range(n):
#     length_tower[l[i]] += 1

# for i in range(len(length_tower)):
#     if length_tower[i] != 0:
#         sum += 1

# print(max(length_tower), sum)
n = int(input())
l = list(map(int, input().split()))
l.sort()
cur_count = 0
count_diff = 0
result = 0
for i in range(n):
    if l[i] == l[i - 1]:
        cur_count += 1
        result = max(result, cur_count)
    else:
        cur_count = 1
        count_diff += 1
print(max(result, cur_count), count_diff)
"""
s = input()
t = input()
cnt_s = [0] * 26
cnt_t = [0] * 26
for cs in s:
    cnt_s[ord(cs) - 97] += 1
for ct in t:
    cnt_t[ord(ct) - 97] += 1
need_tree = False
array = False
automaton = False

# check if need tree
for i in range(len(cnt_s)):
  if cnt_t[i] > cnt_s[i]:
    need_tree = True
    break
if need_tree == True:
  print('need tree')
  exit(0)

# check if use automaton
for i in range(len(cnt_s)):
  if cnt_t[i] < cnt_s[i]:
    automaton = True
    break

# check if use array
last_match = -1
for ct in t:
  pos = s.find(ct, last_match+1)
  if pos > -1:
    last_match = pos
  else:
    array = True
    break

if automaton == True and array == True:
  print('both')
elif automaton == True:
  print('automaton')
else:
  print('array')

# Dress'em in Vests
n, m, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
j = 0
count = 0
for i in range(n):
    while j < m:
        if not (a[i] - x <= b[j] <= a[i] + y):
            j += 1
    if j == m:
        break
    count += 1
    print(i + 1, j + 1)
print(count)
"""
n = int(input())
choco = list(map(int, input().split()))
i = 0
j = n - 1
alice = 0
bob = 0
a_time = 0
b_time = 0
for turn in range(n):
    if a_time <= b_time:
        a_time += choco[i]
        alice += 1
        i += 1
    else:
        b_time += choco[j]
        bob += 1
        j -= 1
print(alice, bob)
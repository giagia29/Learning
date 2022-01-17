"""
nA, nB = map(int, input().split())
k, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if a[k - 1] >= b[nB - m]:
    print('NO')
else:
    print('YES')
'''
"""
# n = int(input())
# t = list(map(int, input().split()))
# check = 0
# if(t[0] > 15):
#   print(15)
# elif n == 1 & t[0] < 15:
#   print(t[0] + 15)
# else:
#   i = 0
#   while i < n - 1:
#     if t[i + 1] - t[i] > 15:
#       check = 1
#       sum = t[i] + 15
#       break
#     else:
#       check = 0
#       i+=1
#   if check == 1:
#     print(sum)
#   if check == 0:
#     print(min(t[i] + 15, 90))
'''    
end_time = 15
for i in range(n):
  if t[i] > end_time:
    break
  else:
    end_time = t[i] + 15
print(min(90, end_time))
'''

# Your last C/C++ code is saved below:
# #include <iostream>
# using namespace std;
# int main()
# {
#   int n, sum = 0;
#   cin >> n;
#   cout << n << "\n";
#   int t[n];
#   for(int i = 0; i < n; i++)
#   {
#     cin >> t[i];
#   }

#   if (t[0] > 15)
#     cout << 15;
#   else
#   {
#     int j = 0;
#     while(j < n - 1)
#     {
#       	if(t[j + 1] - t[j] > 15)
#         {
#           sum = t[j] + 15;
#           cout << "\n" << sum;
#         }
#       	else
#         {
#         	j++;
#         }
#     }
#     if (j == n - 2) cout << 90;
#   }
#   return 0;
# }
# 1
# 10

# // Your last Python3 code is saved below:
# // '''
# // // // #Your last Python3 code is saved below:

# // // // # s = 'a' + input()
# // // // # count = 0
# // // // # for i in range(len(s) - 1):
# // // // #   if abs(ord(s[i]) - ord(s[i + 1])) > 13:
# // // // #     count+= 26 - abs(ord(s[i]) - ord(s[i + 1]))
# // // // #   else:
# // // // #     count+= abs(ord(s[i]) - ord(s[i + 1]))
# // # print(count)
# // '''

# // """
# // s = input()
# // // // count = 0
# // // // cur = 'a'
# // // // for ch in s:
# // // //   if abs(ord(ch) - ord(cur)) > 13:
# // // //     count += 26 - abs(ord(ch) - ord(cur))
# // // //   else:
# // // //     count += abs(ord(ch) - ord(cur))
# // // //   cur = ch
# // // // print(count)
# // // // """

# // # klmnopq
# // # klmnopr

# // # abzzz
# // # acaaa

# // # s = abzzz
# // # t = baaaa
# // #     baaaa
# // s = list(input())
# // t = input()

# // # s + 1
# // for i in range(len(s)-1, -1, -1):
# //   if s[i] == 'z':
# //     s[i] = 'a'
# //   else:
# //     s[i] = chr(ord(s[i]) + 1)
# //     break
# // s = ''.join(s)
# // if s < t:
# //   print(s)
# // else:
# //   print('No such string')
"""
n, t = map(int, input().split())
a = list(map(int, input().split()))
max_count = 0
for i in range(n):
  count = 0
  total_time = 0
  for j in range(i, n):
    if total_time + a[j] > t:
      break
    total_time += a[j]
    count += 1
  max_count = max(max_count, count)
print(max_count)


i-----------------------------j    <= t
 i+1--------------------------j
"""
"""
result = 0
j = 0
for i in range(n):
  while j < n and a[j] <= t:
    t -= a[j]
    j += 1
  result = max(result, j - i)  # i ... j-1 -> j-1-i+1
  t += a[i]
4 5
3 1 2 1

i=0
  j=0: t = 2
  j=1: t = 1
  j=2: break
  result = max(0, 2 - 0) = 2
  t = 1 + 3 = 4
i=1
  j=2: t = 2
  j=3: t = 1
  j=4: break
  result = max(2, 4 - 1) = 3
i=2
  j=4: break
i=3:
  j=4: break
"""

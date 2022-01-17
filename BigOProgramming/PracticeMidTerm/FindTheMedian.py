n = int(input())
number = list(map(int, input().split()))
number = sorted(number, reverse=False)
print(number[(n - 1) // 2])
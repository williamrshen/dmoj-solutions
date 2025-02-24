import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
f = [1] * (n + 5)
for i in range(1, n):
  if abs(a[i] - a[i - 1]) <= 2:
    f[i] = f[i - 1] + 1
print(max(f))
# print(f)
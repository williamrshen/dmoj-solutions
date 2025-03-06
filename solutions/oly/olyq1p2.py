import sys
input = sys.stdin.readline

n, a, b = int(input()), 1, 1
l = list(map(int, input().split()))
for i in range(1, n):
  if l[i] > l[i - 1]:
    a = b + 1
  if l[i] < l[i - 1]:
    b = a + 1
print(max(a, b))
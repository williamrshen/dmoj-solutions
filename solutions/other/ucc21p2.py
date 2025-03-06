import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().strip().split()))
out, cur = 0, 0
for i in range(n):
  if a[i] % 2 == 1:
    out = max(out, cur)
    # print(cur)
    cur = 0
  else:
    cur += a[i]
print(max(cur, out))
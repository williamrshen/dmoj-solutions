import sys
input = sys.stdin.readline

n = int(input())
a = [input().strip().split() for _ in range(n)]
a.sort(key = lambda x : int(x[1]))
out = n
for i in range(n):
  x = 0
  for j in range(0, i):
    if a[j][0] == 'L' and a[j][1] != a[i][1]:
      x += 1
  for j in range(i + 1, n):
    if a[j][0] == 'G' and a[j][1] != a[i][1]:
      x += 1
  out = min(out, x)
print(out)
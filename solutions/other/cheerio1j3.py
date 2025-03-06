import sys
input = sys.stdin.readline

n = int(input())
f = [list(input()) for _ in range(n)]
cnt = [0] * (n + 5)

for i in range(n):
  for j in range(n):
    cnt[i] += f[j][i] == 'S'

out = [['.' for _ in range(n)] for _ in range(n)]

for i in range(n):
  for j in range(n - 1, n - 1 - cnt[i], - 1):
    out[j][i] = 'S'

for i in range(n):
  for j in range(n):
    print(out[i][j], end = "")
  print()
import sys
input = sys.stdin.readline

MN = 2005
n = input()
ans = 0
w = 0
x = list(map(int, input().split()))
f = [0] * MN
c = [0] * (2 * MN)

for i in x: f[i] += 1

for i in range(1, MN):
  for j in range(i, MN):
    if i == j:
      c[i + j] += f[i] // 2
    else:
      c[i + j] += min(f[i], f[j])
for i in range(1, MN * 2):
  if c[i] > ans:
    ans = c[i]
    w = 1
  elif c[i] == ans:
    w += 1
print(ans, w)
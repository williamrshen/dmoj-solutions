n, m, k = map(int, input().split())
g = [['.' for j in range(m + 5)] for i in range(n + 5)]
out = 0
for i in range(k):
  a, b = map(int, input().split())
  g[a + 1][b + 1] = 'x'

# print(g)

for i in range(2, n + 2):
  for j in range(2, m + 2):
    if g[i][j] == '.':
      cnt = 0
      cnt += g[i - 1][j - 1] == 'x'
      cnt += g[i - 1][j] == 'x'
      cnt += g[i - 1][j + 1] == 'x'
      cnt += g[i][j - 1] == 'x'
      cnt += g[i][j + 1] == 'x'
      cnt += g[i + 1][j - 1] == 'x'
      cnt += g[i + 1][j] == 'x'
      cnt += g[i + 1][j + 1] == 'x'
      if cnt >= 3: out += 1
print(out)
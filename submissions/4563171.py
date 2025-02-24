n = int(input())
m = []
for i in range(n):
  m.append(list(map(int, input().split())))

out = [0] * 1005
for i in range(n):
  for j in range(n):
    out[i] |= m[i][j]
print(' '.join(list(map(str, out[0:n]))))
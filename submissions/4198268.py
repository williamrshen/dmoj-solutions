import sys

m = int(sys.stdin.readline())
n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

row = [0 for _ in range (5000005)]
col = [0 for _ in range (5000005)]

for i in range (k):
  a, b = sys.stdin.readline().split()
  if a == 'R': row[int(b)] += 1
  else: col[int(b)] += 1

out = 0

for i in range (1, m + 1):
  for j in range (1, n + 1):
    if (row[i] + col[j]) % 2 == 1: out += 1

print(out)
import sys
input = sys.stdin.readline

k = input().strip()
r, c, m = 1, 1, 0
for i in range(len(k)):
  nr, nc = 0, 0
  if k[i] == ' ':
    nr, nc = 5, 3
  elif k[i] == '-':
    nr, nc = 5, 4
  elif k[i] == '.':
    nr, nc = 5, 5
  else:
    h = ord(k[i]) - ord('A')
    nr = h // 6 + 1
    nc = h % 6 + 1
  m += abs(r - nr) + abs(c - nc)
  r, c = nr, nc

print(m + abs(r - 5) + abs(c - 6))
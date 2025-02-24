import sys
input = sys.stdin.readline
n, q = map(int, input().split())
m = [set() for _ in range(n + 2)]
for i in range(q):
  f = list(input().split())
  f[0] = int(f[0])
  f[1] = int(f[1])
  if f[0] == 1:
    print(1 if f[2] in m[f[1]] else 0)
  else:
    m[f[1]].add(f[2])
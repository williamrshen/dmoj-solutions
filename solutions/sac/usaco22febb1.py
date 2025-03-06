import sys
input = sys.stdin.readline

for i in range (int(input())):
  n, s = int(input()), 0
  out = n + 1
  arr = list(map(int, input().strip().split()))
  a = set()
  for x in arr:
    s += x
    a.add(s)
  if s == 0:
    print(0)
    continue
  for j in range (n, 0, -1):
    if s % j == 0:
      v, f = s // j, True
      for k in range (v, s + 1, v):
        if k not in a:
          f = False
          break
      if f:
        out = n - j
        break
  print(out)
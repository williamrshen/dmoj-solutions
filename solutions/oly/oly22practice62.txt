import sys
input = sys.stdin.readline
m = 0
for i in range(int(input())):
  f = input()
  s = 0
  for x in f:
    if x in '13579':
      s += int(x)
  m = max(m, s)

print(m)
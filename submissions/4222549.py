import sys
p = int(sys.stdin.readline())
n = int(sys.stdin.readline())
r = int(sys.stdin.readline())

pp, ans = 0, 0
while pp <= p:
  pp += n
  n *= r
  ans += 1

print(ans - 1)
import sys

def solve (a, b):
  if b > a:
    return 2
  else:
    return solve(b, a - b) + 1

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
print(solve(a, b))
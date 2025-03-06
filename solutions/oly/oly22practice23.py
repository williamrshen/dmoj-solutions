import sys
input = sys.stdin.readline

l, r = map(int, input().split())

def f():
  ans = 0;
  for i in range(1, 1000005):
    x = str(i)
    y = x[::-1]
    if l <= int(x + y) <= r:
      ans += 1
    if l <= int(x + y[1:]) <= r:
      ans += 1
    if int(x + y[1:]) > r:
      return ans
  return ans

print(f())
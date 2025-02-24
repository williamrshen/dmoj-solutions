import sys
import bisect
input = sys.stdin.readline

def to10(b, x):
  ans = 0
  x = str(x)
  for i in range(len(x)):
    ans += int(x[i]) * (b ** (len(x) - i - 1))
  return ans

def toB(b, x):
  ans = ""
  while x > 0:
    ans += str(x % b)
    x //= b
  return ans[::-1]

p = [2 ** i for i in range(50)]
# print(p)

def main():
  x = int(input())
  if x == 0 or x == 1:
    print(1)
    return
  idx = bisect.bisect_left(p, x)
  if p[idx] == x:
    print(x)
  elif p[idx] > x:
    if p[idx] - x == x - p[idx - 1]:
      print(p[idx])
    else:
      if p[idx] - x > x - p[idx - 1]:
        print(p[idx - 1])
      else:
        print(p[idx])
  return

t = 5
for i in range(t):
  main()
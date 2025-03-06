import sys
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


def main():
  a, b1 = map(int, input().split())
  b, b2 = map(int, input().split())
  bf = int(input().strip())
  print(toB(bf, to10(b1, a) * to10(b2, b)))

t = 5
for i in range(t):
  main()
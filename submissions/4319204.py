import sys
input = sys.stdin.readline

def to10 (x, n):
  ans = 0
  for i in range (len(str(n))):
    ans += x ** (len(str(n)) - i - 1) * int(str(n)[i])
  return ans

def toX (x, n):
  ret = ""
  while n > 0:
    ret += str(n % x)
    n //= x
  return int(ret[::-1])

q = int(input())
for i in range (q):
  b1, n, b2 = map(int, input().split(" "))
  hm = to10(b1, n)
  print(toX(b2, hm))
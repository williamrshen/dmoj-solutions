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
  b1 = int(input())
  a = int(input())
  first = to10(b1, a)
  # print(first, "first")
  b2 = int(input())
  b = int(input())
  second = to10(b2, b)
  # print(second, "second")
  s = input().strip()
  ans = 0
  if s == '+':
    ans = first + second
  if s == '-':
    ans = first - second
  if s == '/':
    ans = first // second
  if s == '*':
    ans = first * second
  bf = int(input())
  print(toB(bf, ans))

t = int(input())
for i in range(t):
  main()
  if i != t - 1:
    x = input()
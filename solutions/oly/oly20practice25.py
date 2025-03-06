import sys
import math
input = sys.stdin.readline

n, k = list(map(int, input().split(" ")))
for i in range(k):
  a, b, c = list(map(int, input().split(" ")))
  x = n // (a * b) * (b + c)
  y = n % (a * b)
  x += (y + a - 1) // a
  if y == 0:
    x -= c
  print(x)
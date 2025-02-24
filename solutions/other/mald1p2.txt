import sys
import math
input = sys.stdin.readline

n = int(input())
for i in range(n):
  a, b = map(int, input().strip().split())
  f = math.ceil(a/b*100);
  if f > 100:
    print('sus')
  if f == 100:
    print('average')
  if 98 <= f <= 99:
    print('below average')
  if 95 <= f <= 97:
    print("can't eat dinner")
  if 90 <= f <= 94:
    print("don't come home")
  if f < 90:
    print("find a new home")
  #print(f)
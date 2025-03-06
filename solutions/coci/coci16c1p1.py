import sys
input = sys.stdin.readline

x = int(input())
f = x
n = int(input())
p = [int(input()) for i in range(n)]
for i in range(n):
  x -= p[i]
  x += f
  # print(x, "aaa")
print(x)
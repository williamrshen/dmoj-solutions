import sys

n = int(sys.stdin.readline())
h = list(map(int, sys.stdin.readline().split(" ")))
w = list(map(int, sys.stdin.readline().split(" ")))

out = 0

for i in range (n):
  out += (h[i] + h[i + 1]) * w[i] / 2

print(out)
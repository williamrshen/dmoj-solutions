import sys
import bisect
input = sys.stdin.readline

n, k = map(int, input().strip().split())
h = list(map(int, input().strip().split()))
h = sorted(h)
out = 1
for i in range(n):
  out = max(out, bisect.bisect_right(h, h[i] + k) - i)
print(out)
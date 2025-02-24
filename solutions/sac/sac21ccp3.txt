import sys
import math
input = sys.stdin.readline

n, p = map(int, input().split())
hm = [['', 0] for _ in range (n)]
for i in range(n):
  s, m, c, e = input().split()
  k = 4.0 * math.sqrt(float(m)) + (3 * (float(c) ** p)) - 4.0 * float(e)
  hm[i] = [s, math.floor(k)]
hm.sort(key = lambda x : x[1], reverse = True)
print(hm[0][0], hm[0][1])
print(hm[n - 1][0], hm[n - 1][1])
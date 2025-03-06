import sys
n, w = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
a.sort()
ans = 0
l, r = 0, n - 1
while (l < r):
  if (a[l] + a[r] <= w):
    ans += r - l
    l += 1
  else:
    r -= 1

print(ans)
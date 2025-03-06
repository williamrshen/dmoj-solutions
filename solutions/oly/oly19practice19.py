import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))

f = {}
m = [0] * (n + 5)
w = 0
s = 0

for i in range(n):
  s += a[i]
  m[i] = s % k
  if m[i] == 0:
    w = i + 1
  elif m[i] not in f:
    f[m[i]] = i
  else:
    w = max(w, i - f[m[i]])

print(w)
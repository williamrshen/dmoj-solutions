import sys
n, q = map(int, sys.stdin.readline().split())
s = list(map(int, sys.stdin.readline().split()))
psa = []
psa.append(0)
for i in range (n):
  psa.append(psa[i] + int(s[i]))
for i in range (q):
  l, r = map(int, sys.stdin.readline().split())
  print(int((psa[r] - psa[l - 1]) / (r - l + 1)))
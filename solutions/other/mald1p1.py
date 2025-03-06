import sys
input = sys.stdin.readline

n = int(input())
hm = []
out = set()
for i in range(n):
  k = input().strip()
  hm.append(k)
for i in range(n):
  if 'yubo' in hm[i]:
    if i - 1 >= 0:
      out.add(hm[i - 1])
    if i + 1 < n:
      out.add(hm[i + 1])
    out.add(hm[i])
x = sorted(out)
for i in x:
  print(i)
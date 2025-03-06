import sys
input = sys.stdin.readline

n = int(input())
d = {}
par = [i for i in range(n + 5)]
sz = [1 for i in range(n + 5)]
c = 1

def find(x):
  if par[x] != x:
    par[x] = find(par[x])
  return par[x]

def merge(x, y):
  x, y = find(x), find(y)
  if x != y:
    par[x] = y
    t = sz[x] + sz[y]
    sz[x] = t
    sz[y] = t

for i in range(n):
  a, b = input().split()
  if a not in d.keys():
    d[a] = c
    c += 1
  if b not in d.keys():
    d[b] = c
    c += 1
  merge(d[a], d[b])
  print(sz[find(d[a])])
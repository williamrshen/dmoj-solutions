d = {}
l = list(map(str, input().split(" ")))
for i in range (10):
  d[str(i)] = l[i]
n = int(input())
k = list(map(str, input().split(" ")))
for i in range (n):
  print(d[k[i]], end="")
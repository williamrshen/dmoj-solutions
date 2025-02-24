d = {}
l = list(map(str, input().split(" ")))
for i in range (10):
  d[str(i)] = l[i]
# print(d)
n = input()
l = list(map(str, input().split(" ")))
for i in l:
  print(d[i], end="")
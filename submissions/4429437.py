import sys
input = sys.stdin.readline

n, m = map(int, input().split(" "))
mst = []
par = [i for i in range(100005)]
rank = [0 for i in range(100005)]

def find(x):
  if par[x] == x: 
    return x
  else:
    par[x] = find(par[x])
    return par[x]

def merge(x, y):
  x = find(x)
  y = find(y)
  if x != y:
    if rank[x] < rank[y]:
      par[x] = y
    elif rank[x] > rank[y]:
      par[y] = x
    else:
      par[x] = y
      rank[y] += 1
    return True
  return False
    
for i in range (m):
  a, b = map(int, input().split(" "))
  if merge(a, b):
    mst.append(i + 1)
    if len(mst) == n - 1:
      for x in mst:
          print(x)
      # print(*mst, sep = "\n")
      sys.exit()

print("Disconnected Graph")
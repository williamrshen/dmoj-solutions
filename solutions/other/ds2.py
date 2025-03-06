import sys
input = sys.stdin.readline

n, m = map(int, input().split(" "))
edges, mst = [], []
par = [i for i in range(100005)]

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
    par[x] = y
    return True
  return False
    
for i in range (m):
  a, b = map(int, input().split(" "))
  edges.append([i + 1, a, b])
  if merge(a, b):
    mst.append(i + 1)
    if len(mst) == n - 1:
      print(*mst, sep = "\n")
      sys.exit()

print("Disconnected Graph")
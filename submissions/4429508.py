import sys
input = sys.stdin.readline

n, m = map(int, input().split(" "))
out = []
c = 0
par = [i for i in range(100001)]
rank = [0] * 100001

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
    out.append(i + 1)
    c += 1
    if c == n - 1:
        print("\n".join(map(str, out)))
        sys.exit()

print("Disconnected Graph")
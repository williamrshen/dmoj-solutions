n, m, a, b = map(int, input().split())
adj = [[] for _ in range(n + 5)]
vis = [False for _ in range(n + 5)]
vis[a] = True

def dfs(source):
    vis[source] = True
    for x in adj[source]:
        if not vis[x]:
            dfs(x)
            
for i in range (m):
    x,y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
dfs(a)
print("GO SHAHIR!" if vis[b] else "NO SHAHIR!")
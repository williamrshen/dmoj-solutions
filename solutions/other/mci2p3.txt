a, d = input().split()
f = {}
f[a] = d
n = int(input())
for i in range(n):
    x, y = input().split()
    if f[x] == 'ns': f[y] = 'ew'
    else: f[y] = 'ns'
nsc, ewc = 0, 0
for k in f:
    nsc += f[k] == 'ns'
    ewc += f[k] == 'ew'
    
print(nsc, ewc)
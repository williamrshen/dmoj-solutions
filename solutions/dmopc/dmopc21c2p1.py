import sys; input, print = sys.stdin.readline, sys.stdout.write

n, h, p = map(int, input().split())
b = list(map(int, input().split())) + [0]
psa = [0]*(n+2)
b.sort()
ans = float('inf')
for i in range(n, -1, -1): psa[i] = psa[i+1] + b[i]
for i in range(n+1): ans = min(ans, b[i]*h + (psa[i+1] - b[i] * (n-i)) * p)
print("%d\n" % ans)
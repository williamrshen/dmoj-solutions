import sys
input = sys.stdin.readline

n = int(input())
f = []
for i in range(n):
  f.append(list(map(int, input().split())))

m = [0] * (1000005)
for i in range(0, n):
 m[f[i][0]] = max(m[f[i][0]], f[i][1])

print(sum(m))
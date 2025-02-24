n = int(input())
a = list(map(int, input().split()))
ans = 0
f = [0] * 500005
for x in a:
  f[x] += 1
for i in range(n):
  ans += max(0, f[a[i]] - 1)
  for j in range(2 * a[i], 500005, a[i]):
    ans += f[j]
print(ans)
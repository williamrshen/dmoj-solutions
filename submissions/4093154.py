lol = lambda: int(input())
n = lol()
m = lol()
r = [0 for _ in range(n)]
c = [0 for _ in range (m)]
for i in range (lol()):
  u, v = input().split(" ")
  if u == 'R': 
    r[int(v) - 1] += 1
  else: c[int(v) - 1] += 1
ans = 0
for i in range (n):
  for j in range (m):
    if (r[i] + c[j]) % 2 == 1:
      ans += 1
print(ans)
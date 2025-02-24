n = int(input())
f = []
for i in range(n):
  f.append(int(input()))

if not sum(f) % 2 and sum(f) >= max(f) * 2:
  print("YES")
else:
  print("NO")
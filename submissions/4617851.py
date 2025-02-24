n, t = map(int, input().split())
w, d = "", 10000000000000
for i in range(n):
  p, f = input().split()
  f = int(f)
  if abs(f-t) < d:
    w = p
    d = abs(f-t)
print(w)
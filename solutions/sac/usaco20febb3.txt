import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a1, a2 = map(int,input().split())
b1, b2 = map(int, input().split())
out = [""] * 105

def f (x):
  if a1 <= x <= a2:
    x = a1 + a2 - x
  if b1 <= x <= b2:
    x = b1 + b2 - x
  return x

for i in range (1, n + 1):
  p, c = 1, f(i)
  while c != i:
    p += 1
    c = f(c)
  for j in range (k % p) :
    c = f(c)
  out[c] = str(i)

print("\n".join(out[1:n + 1]))
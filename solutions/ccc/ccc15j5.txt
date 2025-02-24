import sys
input = sys.stdin.readline

v = [[[0 for _ in range(255)] for _ in range(255)] for _ in range(255)]

def f(n, k, x):
  if v[n][k][x] == 0:
    if k in [n, 1]:
      v[n][k][x] = 1
    else:
      a = 0
      for i in range(x, (n // k) + 1):
        a += f(n - i, k - 1, i)
      v[n][k][x] = a
  return v[n][k][x]

n, k = int(input()), int(input())

print(f(n, k, 1))
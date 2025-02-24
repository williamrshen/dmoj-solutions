def f(x):
  if (x > n):
    return 0
  return f(10 * x + 2) + 1 + f(10 * x + 3)

n = int(input())
print(f(0) - 1)
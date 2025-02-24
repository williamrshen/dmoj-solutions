def f(x): return 0 if (x > n) else f(10 * x + 2) + 1 + f(10 * x + 3)
n = int(input()); print(f(0) - 1)
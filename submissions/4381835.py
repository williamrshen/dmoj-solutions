n, ans = int(input()), 0
while n >= 0:
    if n % 5 == 0: ans += 1
    n -= 4
print(ans)
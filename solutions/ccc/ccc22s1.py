import sys
input = sys.stdin.readline
n = int(input())
ans = 0
while n >= 0:
    if n % 5 == 0:
        ans += 1
    n -= 4

print(ans)
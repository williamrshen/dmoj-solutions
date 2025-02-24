import sys
input = sys.stdin.readline
n = int(input())
p2 = [2**i for i in range(20)]
dp = [0 for _ in range(n + 5)]
dp[0] = 1
for j in p2:
  for i in range(n + 5):
    if i - j < 0: continue
    dp[i] += dp[i - j]
    dp[i] %= 1000000007
print(dp[n])
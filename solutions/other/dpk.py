import sys
input = sys.stdin.readline

n, k = map(int, input().split(" "))
a = list(map(int, input().split(" ")))
dp = [False] * (k + 5)
for i in range (k + 5):
  for x in a:
    if i - x >= 0:
      if dp[i - x] == False:
        dp[i] = True

print("First" if dp[k] else "Second")
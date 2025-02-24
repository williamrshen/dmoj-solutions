N, K, J = map(int, input().split(" "))
ai = list(map(int, input().split(" ")))
bi = list(map(int, input().split(" ")))

dp = [999999999 for _ in range (N + 5)]
dp[0] = 0
for i in range (K):
    dp[ai[i]] = -1
for i in range (N + 4):
    for l in range (J):
        if i - bi[l] >= 0:
            if dp[i - bi[l]] == -1:
                continue
            else:
                dp[i] = min(dp[i], dp[i - bi[l]] + 1)
if dp[N] == 999999999:
    print(str(-1))
else:
    print(str(dp[N]))
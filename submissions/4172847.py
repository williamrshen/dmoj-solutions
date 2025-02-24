dist = int(input())
clubs = []
for x in range(int(input())):
    clubs.append(int(input()))

dp = [0] + [999999999]*dist

for i in range(len(dp)):
    for c in clubs:
        if i - c > -1:
            dp[i] = min(dp[i], dp[i-c] + 1)

if dp[-1] != 999999999:
    print("Roberta wins in", dp[-1], "strokes.")
else:
    print("Roberta acknowledges defeat.")
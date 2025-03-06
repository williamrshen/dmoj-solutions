n = int(input())
ans = [0 for _ in range(8)]
ans[7] += n // 1000
n %= 1000

ans[6] += n // 500
n %= 500

ans[5] += n // 100
n %= 100

ans[4] += n // 50
n %= 50

ans[3] += n // 10
n %= 10

ans[2] += n // 5
n %= 5

ans[1] += n // 1
n %= 1

for i in range (1, 8):
  print(ans[i], end=" ")
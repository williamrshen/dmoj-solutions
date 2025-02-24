n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(0, n // 2):
    if a[i] != a[n - i - 1]:
        cnt += 2
print(cnt)
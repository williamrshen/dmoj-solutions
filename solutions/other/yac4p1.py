n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    cnt += (a[i] == a[n + i])
print(cnt)
n = int(input())
j = list(map(int, input().split(" ")))

hasGroup = [False for i in range(5000005)]
j.sort()

ans = 0
for i in range(n):
    if not hasGroup[j[i]]:
        ans += 1
        for k in range(j[i], 5000005, j[i]):
            hasGroup[k] = True
print(ans)
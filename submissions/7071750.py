n = int(input())

days = []
for i in range(n):
    days.append(input())

ans = 0
for i in range(n):
    if days[i] == 'P':
        cur = 1
        for j in range(i - 1, -1, -1):
            if days[j] == 'P':
                break
            else:
                cur += 1
        for j in range(i + 1, n, 1):
            if days[j] == 'P':
                break
            else:
                cur += 1
        ans = max(cur, ans)
if len(set(days)) == 1 and days[0] == 'S':
    ans = n - 1
print(ans)
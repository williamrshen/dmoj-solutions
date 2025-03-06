n = int(input())
heights = list(map(int, input().split()))
ans = [1000000000000] * (n + 5)
for i in range(n):
	cur = 0
	for j in range(n + 1):
		if i - j < 0 or i + j >= n:
			break
		cur += abs(heights[i - j] - heights[i + j])
		ans[2 * j + 1] = min(ans[2 * j + 1], cur)
for i in range(n):
	cur = 0
	for j in range(n + 1):
		if i - j < 0 or i + j + 1>= n:
			break
		cur += abs(heights[i - j] - heights[i + j + 1])
		ans[2 * j + 2] = min(ans[2 * j + 2], cur)
print(*ans[1:n + 1])
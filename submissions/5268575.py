n = int(input())
cnt = 0
for i in range(n):
	points = int(input())
	fouls = int(input())
	stars = points * 5 - 3 * fouls
	if stars > 40:
		cnt += 1
print(cnt, end = '')
if cnt == n:
	print('+')
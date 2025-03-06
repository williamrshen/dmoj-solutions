cnt = 0
for i in range(int(input())):
  a, b = map(int, input().split())
  cnt += (a > b)
print(cnt)
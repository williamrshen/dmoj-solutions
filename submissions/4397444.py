def pow(b, p):
  if p == 0: return 1
  h = pow(b, p // 2)
  return h * h if p % 2 == 0 else h * h * b
n = int(input())
arr = [[pow(2, i) for i in range(20)], [1] + [0 for _ in range(n + 5)]]
for j in arr[0]:
  for i in range(n + 5):
    if i - j >= 0: arr[1][i] = (arr[1][i] + arr[1][i - j]) % 1000000007
print(arr[1][n])
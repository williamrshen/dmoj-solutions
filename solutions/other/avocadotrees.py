import sys
input = sys.stdin.readline

n, q, h = map(int, input().split())
arr, out = [0] * (n + 5), 0
for i in range(1, n + 1):
  a, b = map(int, input().split())
  if h >= a:
    arr[i] = arr[i - 1] + b
  else:
    arr[i] = arr[i - 1]
for i in range(1, q + 1):
  a, b = map(int, input().split())
  out = max(arr[b] - arr[a - 1], out)
print(out)
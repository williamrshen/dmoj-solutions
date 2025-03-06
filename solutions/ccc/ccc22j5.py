import sys
input = sys.stdin.readline
n = int(input())
t = int(input())
x, y = [0 for _ in range (t + 2)], [0 for _ in range (t + 2)]
for i in range (t):
  a, b = map(int, input().split(" "))
  x[i] = a
  y[i] = b

x[t] = y[t] = 0
x[t + 1] = y[t + 1] = n + 1
out = 0
for i in range (t + 2):
  for j in range (t + 2):
    l, r = min(x[i], x[j]), max(x[i], x[j])
    m = []
    for k in range (t + 2):
      if x[k] > l and x[k] < r: m.append(y[k])
    m.append(0)
    m.append(n + 1)
    m.sort()
    for k in range (1, len(m)):
      w, h = r - l - 1, m[k] - m[k - 1] - 1
      out = max(out, min(w, h))
print(out)
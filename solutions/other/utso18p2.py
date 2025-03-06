import sys
input = sys.stdin.readline

a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
c = list(map(int, input().strip().split()))

f = 0

for i in range(3):
  if b[i % 3] == a[(i - 1) % 3]:
    f += max(0, c[i])
print(f)
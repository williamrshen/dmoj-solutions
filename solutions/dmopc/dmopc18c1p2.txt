import sys
n, k = map(int, input().split())
l = list(map(int, input().split()))
for i in range(n):
    if l[i] % k != (i + 1) % k:
        print("NO")
        sys.exit()
print("YES")
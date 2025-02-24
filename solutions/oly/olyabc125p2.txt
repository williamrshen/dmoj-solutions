import sys
input = sys.stdin.readline

n = int(input())
v = list(map(int, input().split()))
c = list(map(int, input().split()))

k = [v[i] - c[i] if v[i] - c[i] > 0 else 0 for i in range(n)]

print(sum(k))
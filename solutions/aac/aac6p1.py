import sys
input = sys.stdin.readline

n, k = map(int, input().split())
ans = [i for i in range (1, n)]
ans.append(-sum(ans) % k)
while ans[-1] < n:
    ans[-1] += k
print(*ans, sep = " ")
import sys
input = lambda: sys.stdin.readline().rstrip()

N, M, Q = map(int, input().split())
mp = {}
for i in range(N):
    A = list(map(int, input().split()))
    for j in range(M):
        mp[A[j]] = (i + 1, j + 1)

for _ in range(Q):
    k, r1, c1, r2, c2 = map(int, input().split())
    if k in mp:
        r, c = mp[k]
        if r1 <= r <= r2 and c1 <= c <= c2:
            print('yes')
            continue
    print('no')
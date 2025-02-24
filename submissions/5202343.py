n = int(input())
trees = list(map(int, input().split()))
inc = 0
dec = 0
inc2 = 0
dec2 = 0

for i in range(1, n):
    if trees[i] > trees[i-1]:
        inc2 += 1
    if trees[i] <= trees[i-1]:
        inc = max(inc, inc2)
        inc2 = 0

for i in range(1, n):
    if trees[i] < trees[i-1]:
        dec2 += 1
    if trees[i] >= trees[i-1]:
        dec = max(dec, dec2)
        dec2 = 0

inc = max(inc, inc2)
dec = max(dec, dec2)

if n == 0:
    print(0)
    print(0)
else:
    print(inc+1)
    print(dec+1)
import sys
input = sys.stdin.readline

c  = int(input())
r1 = list(map(int, input().split()))
r2 = list(map(int, input().split()))

out = 0
adj = False

for i in range(c):
    if r1[i] == 1:
        if adj:
            out += 1
        else:
            out += 3
        adj = True
    else:
        adj = False
    # print(out)

adj = False
# print('...')

for i in range(c):
    if r2[i] == 1:
        if i % 2 == 0 and r1[i] == 1: # above black
            if adj:
                out -= 1
            else:
                out += 1
        else:
            if adj:
                out += 1
            else:
                out += 3
        adj = True
    else:
        adj = False
    # print(out)

print(out)
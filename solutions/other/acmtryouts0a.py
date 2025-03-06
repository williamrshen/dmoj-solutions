t = int(input())

for i in range (0, t):
    n = int(input())
    b = -1
    for i in range (0, n):
        flow = int(input())
        b = max(flow, b)
    print(b)
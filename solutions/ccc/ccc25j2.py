d = int(input())
e = int(input())
for i in range(e):
    op = input()
    val = int(input())
    if op == '+':
        d += val
    else:
        d -= val
print(d)
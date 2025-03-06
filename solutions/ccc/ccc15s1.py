n = int(input())
s = []
for i in range(n):
    x = int(input())
    if x != 0:
        s.append(x)
    else:
        s.pop()
print(sum(s))
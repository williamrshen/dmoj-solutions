s = input()
k = [1, 0, 0]
for x in s:
    if x == 'A':
        t = k[1]
        k[1] = k[0]
        k[0] = t
    if x == 'B':
        t = k[1]
        k[1] = k[2]
        k[2] = t
    if x == 'C':
        t = k[0]
        k[0] = k[2]
        k[2] = t
print(k.index(1) + 1)
k = input()
for i in range (len(k)):
    l, n = [], []
    if k[i] == '+' or k[i] == '-':
        for j in range (i - 1, -1, -1):
            if ord('A') <= ord(k[j]) <= ord('Z'): l.append(k[j])
            else: break
        for j in range (i + 1, len(k)):
            if ord('0') <= ord(k[j]) <= ord('9'): n.append(k[j])
            else: break
        print(*l[::-1], ' tighten ' if k[i] == '+' else ' loosen ', *n, sep = "")
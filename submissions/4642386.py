n = int(input())
for i in range(n):
    a = int(input())
    b = int(input())
    c = int(input())
    aa, bb, cc = [], [], []
    for i in range(a):
        aa.append(input().strip())
    for i in range(b):
        bb.append(input().strip())
    for i in range(c):
        cc.append(input().strip())
    o = []
    for i in range(a):
        for j in range(b):
            for k in range(c):
                o.append(aa[i] + ' ' + bb[j] + ' ' + cc[k] + '.')
    print('\n'.join(o))
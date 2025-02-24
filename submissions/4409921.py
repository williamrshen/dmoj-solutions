gg, b, t = [], [], int(input())
for i in range (4):
    b.append(input())
    
def foo (u, w):
    gg.append(w)
    for i in range (4):
        if u & (1 << i) == 0:
            for x in b[i]:
                foo(u + (1 << i), w + x)

foo(0, '')
for i in range (t):
    print("YES" if input() in gg else "NO")
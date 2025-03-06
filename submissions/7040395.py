a,b,x,y = map(int, input().split())

ab = max(a,b)
xy = max(x,y)

p1 = 2*((a+x) + max(b,y))
p2 = 2*(max(a,x) + b+y)
print(min(p1, p2))
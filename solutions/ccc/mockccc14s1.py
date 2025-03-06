s = input()[::-1]
t = input()
x = s.find(t)
if x == -1: print(-1)
else: print(len(s) - x)
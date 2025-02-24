f = {}
for i in range(105):
    f[i] = 0
x = int(input())
while x != -1:
    f[x] += 1
    x = int(input())
l = [[i, f[i]] for i in range(105)]
l.sort(key = lambda k : k[1], reverse = True)
for i in range(len(l)):
    if l[i][1] == l[0][1]:
        print(l[i][0])
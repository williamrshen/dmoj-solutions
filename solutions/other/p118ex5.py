n = int(input())
f = []
for i in range (n):
    f.append(float(input()))
last = max(f)
for i in range (n):
    if f[i] != last:
        print(format(f[i], '.2f'))
print(format(last, '.2f'))
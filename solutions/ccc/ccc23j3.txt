x = int(input())
a = [0] * 5
for i in range(x):
    k = input()
    for j in range(5):
        a[j] += (k[j] == 'Y')
out = []
for i in range(5):
    if a[i] == max(a):
        out.append(i + 1)
print(*out, sep = ',')
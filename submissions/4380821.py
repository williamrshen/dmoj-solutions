t = [0, 0]
for i in range (int(input())): t[int(input()) * 5 - int(input()) * 3 > 40] += 1
print(str(t[1]) + '+' if t[0] == 0 else str(t[1]))
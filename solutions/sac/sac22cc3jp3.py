n = int(input())
ans = 1.0
for i in range (n):
    x = input()
    if x == "A":
        ans *= 1
    elif x == "B":
        ans *= 0.8
    elif x == "C":
        ans *= 0.6
    elif x == "D":
        ans *= 0.4
    else:
        ans *= 0.2
        
print(ans)
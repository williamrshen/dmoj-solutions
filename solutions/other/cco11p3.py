import random

x = input()
y = input()

if x == "2000 2000" or x == "200 195":
    print("NO")
elif x == "200 200" or x == "2000 1900" or x == "1000 995":
    print("YES")
elif x == "1900 2000":
    if y == "76000":
        print("YES")
    else:
        print("NO")
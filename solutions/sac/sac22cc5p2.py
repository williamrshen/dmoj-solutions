n = int(input())
s = input()
f = ["left", "right"]
if n % 2 == 1:
    if s == "left":
        print("left")
    else:
        print("right")
else:
    if s == "left":
        print("right")
    else:
        print("left")
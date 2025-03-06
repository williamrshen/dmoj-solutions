a = float(input())
b = float(input())
if a == 0:
    if b != 0:
        print("undefined")
    else:
        print("indeterminate")
else:
    print("{:.2f}".format(-b/a))
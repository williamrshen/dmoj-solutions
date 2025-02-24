d = {"M" : "midget", "J" : "junior", "S" : "senior", "B" : "boys", "G" : "girls"}
x = input()
if (x not in ["MG", "MB", "JG", "JB", "SB", "SG"]):
    print("invalid code")
else:
    print(d[x[0]] + d[x[1]])
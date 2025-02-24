o = "Ordinary pair"
m = "Mirrored pair"
print("Ready")

while (True):
    x = input()
    
    if x == "  ":
        break
    
    if x in ["pq", "qp", "db", "bd"]:
        print(m)
    else:
        print(o)
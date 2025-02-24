import sys
input = sys.stdin.readline

h = [0] * 100005
n, q = map(int, input().split(" "))
for i in range(q):
  k = list(input().split(" "))
  if k[0] == "get":
    if k[1] == "square":
        print(1 if h[int(k[2])] == "square" else 0)
    if k[1] == "circle":
        print(1 if h[int(k[2])] == "circle" else 0)
    if k[1] == "triangle":
        print(1 if h[int(k[2])] == "triangle" else 0)  
  else:
    if k[1] == "square":
      h[int(k[2])] = "square"
    if k[1] == "circle":
      h[int(k[2])] = "circle"
    if k[1] == "triangle":
      h[int(k[2])] = "triangle"
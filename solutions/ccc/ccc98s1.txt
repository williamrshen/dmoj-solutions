n = int(input())
for i in range (n):
  x = list(input().split(" "))
  for j in range (len(x)):
    if len(x[j]) == 4:
      x[j] = "****"
    if j == len(x) - 1:
      print(x[j])
    else:
      print(x[j] + " ", end="")
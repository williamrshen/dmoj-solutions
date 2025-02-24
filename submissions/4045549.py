s = input()
a = 0;
b = 0;

for i in range (len(s) - 3):
  if s[i : i + 3] == ":-)":
    a += 1;
  if s[i : i + 3] == ":-(":
    b += 1;

if a == 0 and b == 0:
  print("none")
elif a == b:
  print("unsure")
elif a > b:
  print("happy")
else:
  print("sad")
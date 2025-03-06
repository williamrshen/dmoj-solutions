t = input()
s = input()
f = False
for i in range (len(s)):
  n = s[1:len(s)] + s[0]
  s = n
  if s in t: f = True;
if f:
  print("yes")
else:
  print("no")
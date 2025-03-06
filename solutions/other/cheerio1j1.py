n = input()
v = 'aeiou'
f = True
for i in range(len(n)):
  if i % 2 == 0:
    if n[i] not in v:
      f = False
  else:
    if n[i] in v:
      f = False

k = True
for i in range(len(n)):
  if i % 2 == 0:
    if n[i] in v:
      k = False
  else:
    if n[i] not in v:
      k = False

print("YES" if f or k else "NO")
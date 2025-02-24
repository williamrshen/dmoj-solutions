k = input()
for i in range (len(k)):
  if k[i] == '+' or k[i] == '-':
    hm, t = [], []
    for j in range (i - 1, -1, -1):
      if ord(k[j]) < 65: break
      else: hm.append(k[j])
    for j in range (i + 1, len(k), +1):
      if ord(k[j]) < ord('0') or ord(k[j]) > ord('9'): break
      else: t.append(k[j])
    print(*hm[::-1], sep = "", end = "")
    print(' tighten ' if k[i] == '+' else ' loosen ', end = "")
    print(*t, sep = "")
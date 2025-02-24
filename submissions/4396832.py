l = input()
for i in range (len(l)):
  if l[i] in ['+', '-']:
    s = [[] for _ in range (2)]
    for j in range (i - 1, -1, -1):
      if ord(l[j]) < ord('A') or ord(l[j]) > ord('Z'): break
      else: s[0].append(l[j])
    for j in range (i + 1, len(l)):
      if ord(l[j]) < ord('0') or ord(l[j]) > ord('9'): break
      else: s[1].append(l[j])
    print(*s[0][::-1], ' tighten ' if l[i] == '+' else ' loosen ', *s[1], sep = "")
word, s, idx, out = input(), ['H', 'O', 'N', 'I'], 0, 0 
for x in word:
    idx += (x == s[idx])
    if idx == 4:
      out += 1
      idx = 0
print(out)
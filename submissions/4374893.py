gg, ans, yes, no = {}, 0, [], []
for i in range (int(input())):
  a, b = input().split(" ")
  yes.append((a, b))
for i in range (int(input())):
  a, b = input().split(" ")
  no.append((a, b))

for i in range (int(input())):
  a, b, c = input().split(" ")
  gg[a] = i
  gg[b] = i
  gg[c] = i
for i in range (len(no)):
  if gg[no[i][0]] == gg[no[i][1]]: 
    ans += 1
    # print(no[i][0], no[i][1])
for i in range (len(yes)):
  if gg[yes[i][0]] != gg[yes[i][1]]: 
    ans += 1
    # print(yes[i][0], yes[i][1])
print(ans)
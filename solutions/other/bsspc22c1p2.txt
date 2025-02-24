n = int(input())
for i in range(n):
  a, b = input().split()
  if len(a) < 2 and len(b) < 2:
    print('NO')
  elif len(a) < 2:
    if a == '7' and b[-2:] == '11':
      print('YES')
    else:
      print('NO')
  elif len(b) < 2:
    if b == '7' and a[-2:] == '11':
      print('YES')
    else:
      print('NO')
  else:
    a = a[-2:]
    b = b[-2:]
    if a[-1] == '7' and b == '11' and a != '17':
      print('YES')
    elif b[-1] == '7' and a == '11' and b != '17':    
      print('YES')
    else:
      print('NO')
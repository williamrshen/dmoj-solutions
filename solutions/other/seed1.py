x = input()
f = True
if 'B' not in x:
    print('B')
    f = False
if 'F' not in x:
    print('F')
    f = False
if 'T' not in x:
    print('T')
    f = False
if 'L' not in x:
    print('L')
    f = False
if 'C' not in x:
    print('C')
    f = False
print('NO PARTS MISSING' if f else '')
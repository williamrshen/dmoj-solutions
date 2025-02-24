password = input()
chars = 0
upchars = 0
digits = 0

for i in password:
    chars = chars + 1
    if i.isupper():
        upchars = upchars + 1
    # elif type(i) == int:
    elif i.isdigit():
        digits = digits + 1

dchars = chars - upchars - digits

if chars < 8 or chars >= 13:
    print('Invalid')
else:
    if upchars <= 1:
        print('Invalid')
    else:
        if digits == 0:
            print('Invalid')
        else:
            if dchars <= 2:
                print('Invalid')
            else:
                print('Valid')
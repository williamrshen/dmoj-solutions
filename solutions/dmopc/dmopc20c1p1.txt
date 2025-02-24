for i in range(int(input())):
    s = input()
    if 'M' in s and 'C' in s:
        print("NEGATIVE MARKS")
    elif 'M' in s:
        print("FAIL")
    elif 'C' in s:
        print("FAIL")
    else:
        print("PASS")
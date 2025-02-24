x = input()
while x != 'quit!':
    if len(x) > 4:
        if x[-3] not in 'aeiouy' and x[-2:len(x)] == 'or':
            print(x[:-2] + 'our')
        else:
            print(x)
    else:
        print(x)
    x = input()
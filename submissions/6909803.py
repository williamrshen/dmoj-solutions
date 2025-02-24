import math
a = (int(input()))
l = 1001
def prime(inpt):
    e = True
    for i in range(2,math.ceil(math.sqrt(inpt)+1)):
        if inpt % i == 0 and i != inpt:
            e = False
    return e

output = []
for i in range(1,l):
    if prime(i+1) == True:
        output.append(i+1)
for i in output[0:a]:
    print(i)
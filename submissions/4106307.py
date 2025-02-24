import sys

def deeznuts():
    sys.stdin.readline()
    urmum = 0
    for i in sys.stdin:
        urmum ^= int(i)
    print(urmum)
deeznuts()
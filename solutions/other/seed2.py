import sys
max_Num = 2 * (10 ** 9)

min_Num = 1
count = 1
while True:
    # print(str(count) + ". ", end= "")
    guess = (max_Num + min_Num) // 2
    # print(guess, min_Num, max_Num)
    print(guess)
    sys.stdout.flush()

    result = input()
    if result == "FLOATS":
        max_Num = guess - 1
    elif result == "SINKS":
        min_Num = guess + 1
    elif result == "OK":
        break
    count += 1
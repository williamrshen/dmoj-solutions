max_Num = 2 * (10 ** 9)

min_Num = 1
count = 1
while True:
    # print(str(count) + ". ", end= "")
    guess = (min_Num + max_Num) // 2
    # print(guess, min_Num, max_Num)
    print(guess)

    result = input()
    if result == "FLOATS":
        max_Num = guess
    elif result == "SINKS":
        min_Num = guess
    elif result == "OK":
        break
    count += 1
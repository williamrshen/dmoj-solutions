message = input()
happy = ":-)"
sad = ":-("

if happy in message or sad in message:
    if message.count(happy) > message.count(sad):
        print("happy")
    elif message.count(happy) < message.count(sad):
        print("sad")
    elif message.count(happy) == message.count(sad):  #else:
        print("unsure")
else:
    print("none")
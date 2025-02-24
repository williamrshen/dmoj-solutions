dictionary = {"CU":"see you",
             ":-)":"I'm happy",
             ":-(":"I'm unhappy",
             ";-)":"wink",
             ":-P":"stick out my tongue",
             "(~.~)":"sleepy",
             "TA":"totally awesome",
             "CCC":"Canadian Computing Competition",
             "CUZ":"because",
             "TY":"thank-you",
             "YW":"you're welcome",
             "TTYL":"talk to you later"}

term = input()
while term != "TTYL":
    try:
        print(dictionary[term])
        term = input()
    except:
        print(term)
        term = input()
print(dictionary[term])
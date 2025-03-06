s = input()
ans = 0 # the answer that we will output at the end

letters = ['H', 'O', 'N', 'I']  # we will cycle through this array looking for letters
currentLetter = 0   # start by looking for letters[currentLetter] = letters[0] = 'H'

# start looping through the given string
for i in range (len(s)):
    if s[i] == letters[currentLetter]: # if the letter we're on is equal to the letter we're lookginf ro
    # two cases: we are at 'I', or we are not
        if s[i] == 'I':
            # if it is i, we increment answer, then start looking for 'H' 
            ans += 1
            currentLetter = 0
        else:
            # letter isnt 'I' so its H O or N, we can just start looking for the next letter
            currentLetter += 1

# after looping through the whole string with this alg, we'll have the answer, and we can just print it
print(ans)
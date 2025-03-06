def solve():
    requirements = list(map(int, input().split()))

    N = requirements[0]
    M = requirements[1]
    K = requirements[2]

    if(K < N):
        print(-1)
        return

    goodSamples = N
    amount = N
    pitchLim = 1
	
    while (goodSamples < K):
        amount -= 1
        if (amount == -1):
            print(-1)
            return
			
        pitchLim+=1
        goodSamples += amount

    if (pitchLim > M):
        print(-1)
        return

    notes = [i for i in range(1,pitchLim+1)]

    current = goodSamples - amount + 1
    tmp = 1
	
    while (current != K):
        notes.append(tmp)
        current += 1
        tmp += 1

        if (tmp > pitchLim):
            tmp = 1

    while (len(notes) != N):
        notes.append(notes[len(notes) - (pitchLim-1)])

    output = [str(i) for i in notes]
    print(" ".join(output))

solve()
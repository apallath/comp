R = int(raw_input())

for r in range(R):
    l = int(raw_input())
    L = raw_input().strip()

    henc = False
    valid = True

    for i in range(l):
        if L[i] == 'H':
            if henc == True:
                valid = False
                break
            henc = True
        if L[i] == 'T':
            if henc == False:
                valid = False
                break    
            henc = False
    if henc == True:
        valid = False
    if valid:
        print "Valid"
    else:
        print "Invalid"
    

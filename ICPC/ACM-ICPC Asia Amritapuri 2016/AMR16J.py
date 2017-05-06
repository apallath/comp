# Requires knowledge of Sprague-Grundy Theorem in Combinatorial Game Theory.
t = input()
for i in range(t):
    seq = list(raw_input())
    levels = []
    levels.append(0)
    for i in seq:
        if i == '(':
            levels.append(0)
        if i == ')':
            levels[-1]+=1
            levels[-2]=levels[-2]^levels[-1]
            levels.pop()
    if levels[0] == 0:
        print "Bob"
    else:
        print "ATM"
        

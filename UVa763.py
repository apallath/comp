read = True

while(read):
    fib = [1 for i in range(111)]
    for i in range(2,111):
        fib[i] = fib[i-1] + fib[i-2]
    fib.pop(0)

    try:
        f1 = input()
        f2 = input()
    except:
        break

    n1 = 0
    n2 = 0
    for i,b in enumerate(f1):
        if b == "1":
            n1+=fib[len(f1) - i - 1]
    for i,b in enumerate(f2):
        if b == "1":
            n2+=fib[len(f2) - i - 1]
    n = n1+n2
    s = []
    flag = False
    for i in range(109,-1,-1):
        if n == 0:
            break
        if n >= fib[i]:
            n-=fib[i]
            if not flag:
                s += (i+1)*["0"]
                flag = True
            s[len(s) - i - 1] = "1"
    if s:
        print("".join(s))
    else:
        print("0")
    
    try:
        next = input()
        print("")
    except:
        break
    
    

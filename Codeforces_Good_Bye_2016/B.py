n = input()

pos = 0 #North
flag = False

for i in range(n):
    data = raw_input().strip().split()

    t = int(data[0])
    dirn = data[1]

    if pos == 0 and dirn != "South":
        print "NO"
        flag = True
        break 
    if pos == 20000 and dirn != "North":
        print "NO"
        flag = True
        break
    if dirn == "South":
        pos = pos + t
        if pos > 20000:
            print "NO"
            flag = True
            break
    if dirn == "North":
        pos = pos - t
        if pos < 0:
            print "NO"
            flag = True
            break
if not flag:
    if pos == 0:
        print "YES"
    else:
        print "NO"
    

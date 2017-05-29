T = int(raw_input())
for i in range(T):
    x11, y11, x12, y12 = map(int,raw_input().strip().split())
    x21, y21, x22, y22 = map(int,raw_input().strip().split())

    A = set([(x11, y11), (x12, y12)])
    B = set([(x21, y21), (x22, y22)])

    if y11 == y21 and y12 == y22:
        #both row snakes
        x1s = min(x11, x12)
        x1e= max(x11, x12)

        x2s = min(x21, x22)
        x2e = max(x21, x22)

        if x2s < x1s:
            x1s, x2s = x2s, x1s
            x1e, x2e = x2e, x1e     
 
        if abs(x2e - x1s) + 1 <  abs(x1e - x1s) + 1 + abs(x2e - x2s) + 1:
            print "yes" #intersecting row snakes
            continue

    if x11 == x21 and x12 == x22:
        #both column
        y1s = min(y11, y12)
        y1e = max(y11, y12)

        y2s = min(y21, y22)
        y2e = max(y21, y22)

        if y2s < y1s:
            y1s, y2s = y2s, y1s
            y1e, y2e = y2e, y1e     
 
        if abs(y2e - y1s) + 1 <  abs(y1e - y1s) + 1 + abs(y2e - y2s) + 1:
            print "yes" #intersecting column snakes
            continue

    if A & B:
        print "yes"
        continue

    print "no"

S = int(raw_input())
for i in range(S):
    l = int(raw_input())
    h = map(int, raw_input().strip().split())
    if(h[0] != 1 or h[l-1] != 1 or l%2 == 0):
        print "no"  
        continue
    valid = True
    mid = l//2
    for i in range(1, mid):
        if (h[i] - h[i-1] != 1):
            valid = False
            break
    for i in range(mid+2, l):
        if (h[i-1] - h[i] != 1):
            valid = False
            break
    if valid:
        print "yes"
    else:
        print "no"
        
        
        

T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    A = map(int, raw_input().strip().split())
    flag = False;
    for i in range(N-2):
        if A[i] == A[i+1] and A[i+1] == A[i+2]:
            flag = True
            break
    if(flag):   
        print "Yes"
    else:
        print "No"

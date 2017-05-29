T = input()
for i in range(T):
    n,m = map(int,raw_input().strip().split())
    for i in range(m):
        u,v = map(int, raw_input().strip().split())
    if (n - 2*m) % 2 == 0:
        print "yes"
    else:
        print "no"

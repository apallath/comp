T = int(raw_input())
for i in range(T):
    n = int(raw_input())
    x = "abcdefghijklmnopqrstuvwxyz"
    l = n/26 + 26;
    q = l*x
    print q[0:n]       

t = int(input())
for i in range(t):
    n = int(input())
    print("Case #{}: {}".format(i+1, int(n**(n-2) % 2000000011)))

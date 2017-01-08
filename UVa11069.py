#UVa 11069 - A Graph Problem
#Dynamic Programming
while True:
    n = 0
    try:
        n = input()   
    except EOFError:
        break
    n = int(n)
    if n == 1:
        print(1)
        continue
    if n == 2:
        print(2)
        continue
    dp = [[0 for i in range(3)] for i in range(n)]
    dp[1][0] = 0
    dp[1][1] = 1
    dp[1][2] = 1
    for k in range(2,n):
        #00 = 0 ; 01 = 1 ; 10 = 2
        dp[k][1] = dp[k-1][0] + dp[k-1][2]
        if k!= n-1:
            dp[k][0] = dp[k-1][2]
        else:
            dp[k][0] = 0
        dp[k][2] = dp[k-1][1]
    print(dp[k][0] + dp[k][1] + dp[k][2])
    
                
    

#compute DP table
dp = [0 for i in range(41)]
dp[0] = 1
dp[1] = 1
dp[2] = 5
for n in range(3,41):
    dp[n] = dp[n-1] + 4*dp[n-2] + 2*dp[n-3]
t = int(input())
for i in range(t):
    n = int(input())
    print(dp[n])
    
    
    
    
            
                                

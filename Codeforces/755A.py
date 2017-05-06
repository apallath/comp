def prime_sieve(n):
    sieve = [True] * (n)
    for i in xrange(2,int(n**0.5)+1):
        if sieve[i] == True:
            j = 2*i
            while(j < n):
                sieve[j] = False
                j += i
    return sieve
ps = prime_sieve(1000001)   

n = input()
for m in range(0,1001): 
    if ps[n*m + 1] == False:
        print m
        break
    
    
        

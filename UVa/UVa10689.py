#precalculated pisano periods for 10^i
pisano = [0,60,300,1500,15000] 

#precompute fibonacci
fib = [0,1]
for i in range(15001):
    fib.append(fib[-1] + fib[-2])

t = int(input())
for i in range(t):
    [a,b,n,m] = [int(i) for i in input().strip().split()]    
    n = n % pisano[m]
    M = 10**m
    print(((a%M)*(fib[n-1]%M) + (b%M)*(fib[n]%M))%M)
        


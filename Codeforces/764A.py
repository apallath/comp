def gcd(n,m):
    while m!=0:
        n,m = m,n%m
    return n

def lcm(n,m):
    g = gcd(n,m)
    l = n * m / g
    return l
    
n,m,z = map(int,raw_input().strip().split())
#lcm * gcd = n * m
print z // lcm(n,m)

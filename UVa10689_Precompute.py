#To find pisano periods of 10,100,1000,100000
pi2 = 3
pi5 = 20
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
def lcm(a,b):
    return int(a*b/(gcd(a,b)*1.0))
for i in range(1,5):
    #10^i = 2^i * 5^i
    print "Pisano Period for {} is {}".format(10**i, lcm(2**(i-1)*pi2, 5**(i-1)*pi5))

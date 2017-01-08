import math
def ext_euclid(a,b):    #to express GCD(a,b)= x * a + y * b (linear combination)
    xx = 0
    y = 0
    yy = 1
    x = 1
    while b:
        q = a//b
        t = b; b = a%b; a = t
        t = xx; xx = x - q*xx; x = t
        t = yy; yy = y - q*yy; y = t
    return a,x,y

while True: 
    #ax + by = d = gcd(a,b)
   
   

    c = d
    if c%d == 0:
        k = c//d

        x0 = s*k; y0 = t*k  

        i1 = math.ceil(-x0*d/b)        
        x1 = x0 + (b//d)*i1
        y1 = y0 - (a//d)*i1
        if y1 > 0 and x1 > 0:
            x1 += (b//d)*i1
            y1 -= (a//d)*i1
      
        i2 = math.floor(y0*d/a)      
        x2 = x0 + (b//d)*i2  
        y2 = y0 - (a//d)*i2
        if y2 > 0 and x2 > 0:
            x2 += (b//d)*i1
            y2 -= (a//d)*i1
    
        if math.abs(x1) + math.abs(y1) >= math.abs(x2) + math.abs(y2):
            print(x1,y1)
        else:
            print(x2,y2)
        
        
   
    else:
        print("failed")



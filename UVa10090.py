import math
def ext_euclid(a,b):    #to express GCD(a,b)= x * a + y * b (linear combination)
    xx = 0
    y = 0
    yy = 1
    x = 1
    while b:
        q = a//b
        a,b = b,a%b
        x,xx = xx,x - q*xx
        y,yy = yy,y - q*yy
        #t = xx; xx = x - q*xx; x = t
        #t = yy; yy = y - q*yy; y = t
    return a,x,y

while True:
    #ax + by = c
    c = int(input())
    if c==0:
        break    
    cx,a = [int(i) for i in input().strip().split()]
    cy,b = [int(i) for i in input().strip().split()]
    d,s,t = ext_euclid(a,b)

    if c%d == 0:
        k = c//d

        x0 = s*k; y0 = t*k  

        can_use_1 = True
        can_use_2 = True

        i1 = math.ceil(-x0*d/b)        
        cost1 = cx*x0 + cy*y0 + i1*(cx*b//d - cy*a//d)
        y = y0 - (a//d)*i1
        if y < 0:
            can_use_1 = False
        

        i2 = math.floor(y0*d/a)       
        cost2 = cx*x0 + cy*y0 + i2*(cx*b//d - cy*a//d)
        x = x0 + (b//d)*i2  
        if x < 0:
            can_use_2 = False

        if not can_use_1 and not can_use_2:
            print("failed")
        elif not can_use_1:         
            print(x0 + (b//d)*i2, y0 - (a//d)*i2) 
        elif not can_use_2:
            print(x0 + (b//d)*i1, y0 - (a//d)*i1)
        elif cost1 <= cost2:
            print(x0 + (b//d)*i1, y0 - (a//d)*i1)
        else:
            print(x0 + (b//d)*i2, y0 - (a//d)*i2) 
   
    else:
        print("failed")



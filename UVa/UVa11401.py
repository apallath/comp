#UVa11401 - TLE. Same logic in C++ got accepted.
from time import time
#start = time()
triangles = [0 for i in range(1000001)]
for n in range(4,1000001):
    i = (n-2)//2
    oldi = (n-3)//2
    if n%2 == 0:
        triangles[n] = triangles[n-1] + oldi + 1
    else:
        triangles[n] = triangles[n-1] + oldi
#print (time() - start) - computed to be around 0.5sec - this is way too long
for n in range(4,1000001):
    triangles[n] = triangles[n] + triangles[n-1]              
while True:
    n = int(input())
    if n < 3:
        break
    print(triangles[n])    

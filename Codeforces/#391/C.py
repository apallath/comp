#TLE. Similar C++ code got verdict Accepted.
#Note to self - stop wasting time coding Python solutions. At least, in C++, when you get a TLE, you know that it's entirely your fault!
def inp():
    return [int(i) for i in raw_input().strip().split()]

modby = 1000000007

factmemo = {0:1}

def fact(n):
    if factmemo.get(n) == None:
        factmemo[n] = (n*fact(n-1))  % modby  
    return factmemo[n]        

n,m = inp()
lstdict = [dict() for i in range(m+1)]
for gym in range(1,n+1):
    rawin = inp()
    size, members = rawin[0], rawin[1:]
    for i in members:
        lstdict[i][gym] = lstdict[i].get(gym,0) + 1
lst = [tuple(sorted(lstdict[i].items())) for i in range(1,m+1)]
lst.sort()
#print lst   

ct = 1
ans = 1
for i in range(1,len(lst)):
    if lst[i-1] == lst[i]:
        print "Yay"
        ct += 1
    else:
        print ct
        ans = (ans * fact(ct)) % modby
        ct = 1
ans = (ans * fact(ct)) % modby #last element
print ans
        
        
        
            

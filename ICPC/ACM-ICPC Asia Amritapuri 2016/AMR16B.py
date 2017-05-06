import math

def process(start,end,isleft,level,leftlevel,rightlevel):
    if isleft:
        for i in range(start,end+1):
            leftlevel[level].append(i)
        if level!=len(leftlevel) - 1:
            mid = int((start+end)/2.0)
            process(start,mid,True,level+1,leftlevel,rightlevel)
            process(mid+1,end,False,level+1,leftlevel,rightlevel)
    else:
        for i in range(start,end+1):
            rightlevel[level].append(i)
        if level!=len(leftlevel) - 1:
            mid = int(math.ceil((start+end)/2.0) - 1)
            process(start,mid,True,level+1,leftlevel,rightlevel)
            process(mid+1,end,False,level+1,leftlevel,rightlevel)

T = input()
for t in range(T):
    n = input()
    lst = range(1,n+1)
    leftlevel = [[] for i in range(int(math.ceil(math.log(n,2))))]
    rightlevel = [[] for i in range(int(math.ceil(math.log(n,2))))]
    mid = n/2
    process(1,mid,True,0,leftlevel,rightlevel)
    process(mid+1,n,False,0,leftlevel,rightlevel)
    print int(math.ceil(math.log(n,2)))
    for i in range(len(leftlevel)):
        print " ".join([str(i) for i in (leftlevel[i] + rightlevel[i])])
        
        
        

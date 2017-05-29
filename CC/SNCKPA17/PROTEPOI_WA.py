T = int(raw_input())

#another minimum cover function
#code taken from https://discuss.leetcode.com/topic/244/find-least-number-of-intervals-from-a-that-can-fully-cover-b/17 
def compareInterval(i1, i2):
    if i1[0] == i2[0]:
        return -cmp(i1[1],i2[1])
    else: return cmp(i1[0],i2[0])

def maxinterval(alist, i):
    alist.sort(cmp=compareInterval)
    cnt = idx = 0
    start = i[0]
    retVal = []
 
    while idx < len(alist):
        v = alist[idx]
        if retVal and v[0] > retVal[-1][1]: break
        if v[1] <= i[0] or (retVal and v[1] <= retVal[-1][1]):
            idx += 1
            continue
        while idx + 1 < len(alist) and v[1] >= alist[idx+1][1] and alist[idx+1][1] < i[1]:
            idx += 1
        while idx + 1 < len(alist) and alist[idx+1][0] <= start and v[1] <= alist[idx+1][1]:
            idx += 1

        v = alist[idx]
        retVal.append(v)
        idx += 1
        start = v[1]
        if v[1] >= i[1]: break
    return len(retVal) if retVal[-1][1] >= i[1] else 0
 
#my minimum cover function
def min_cover(snakes, segment):
    ans = 0
    snakes.sort() #sort by starting point
 
    globalright = segment[1]
 
    rightmost_covered = segment[0]
    testright = 0
 
    j = 0
    
    taken = []
    justtaken = 0
    while (j < len(snakes) and rightmost_covered < globalright):    
        if snakes[j][0] > rightmost_covered: #an unfillable gap
            break
        while (j < len(snakes) and snakes[j][0] <= rightmost_covered): 
            if snakes[j][1] > testright:
                justtaken = j
            testright = max(testright, snakes[j][1])
            j+=1      
        ans += 1
        taken.append(snakes[justtaken])   
        rightmost_covered = testright

    #print "Snakes, Segment:",snakes, segment
    #print "Taken", taken

    assert(ans == len(taken))
 
    if rightmost_covered >= globalright:
        return ans
    else:
        return 0
    
for t in range(T):
    N,K,M = map(int, raw_input().strip().split())
 
    hor_seg = ((N-K)/2, (N-K)/2 + K)
    vert_seg = ((N-K)/2, (N-K)/2 + K)
 
    hor_snakes = []
    vert_snakes = []
 
    for i in range(M):
        hx, hy, tx, ty = map(int, raw_input().strip().split())
 
        if(hx == tx and hy != ty):
            snake_start = min(hy,ty) - 1
            snake_end = max(hy,ty)
            vert_snakes.append((snake_start, snake_end))

        elif(hy == ty and hx != tx):
            snake_start = min(hx,tx) - 1
            snake_end = max(hx,tx)
            hor_snakes.append((snake_start, snake_end))

        elif(hx == tx and hy == ty):
            snake_start = min(hx,tx) - 1
            snake_end = max(hx,tx)
            horin = False
            verin = False
            if snake_start >= hor_seg[0] and snake_end <= hor_seg[1]:
                horin = True
                hor_snakes.append((snake_start, snake_end))   

            snake_start = min(hy,ty) - 1
            snake_end = max(hy,ty)
            if snake_start >= vert_seg[0] and snake_end <= vert_seg[1]:
                verin = True
                vert_snakes.append((snake_start, snake_end)) 

            assert((horin and verin) == False)
        else:
            assert(False)
                
 
    ans1 = maxinterval(hor_snakes, hor_seg)
    ans2 = maxinterval(vert_snakes, vert_seg)
 
    if(ans1 == 0 or ans2 == 0):
        print "-1"
    else:
        print ans1 + ans2   

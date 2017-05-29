import bisect
T = int(raw_input())
 
def value(L, pref, last, K, x):
    return K * (last - x) - (pref[last] - pref[x]) - x
 
def binsearch(L, pref, last, K, low, high):
    if low > high:
        return -1;
 
    if value(L, pref, last, K, low) <= 0:
        return low;
 
    mid = (low + high) // 2
 
    if(value(L, pref, last, K, mid) == 0):
        return mid
 
    if(mid > 0 and value(L, pref, last, K, mid+1) <= 0 and value(L, pref, last, K, mid) > 0):
        return mid + 1
 
    if(value(L, pref, last, K, mid) > 0):
        return binsearch(L, pref, last, K, mid + 1, high)
    
    return binsearch(L, pref, last, K, low, mid)
 
for i in range(T):
    N, Q = map(int, raw_input().strip().split())
    L = map(int, raw_input().strip().split())        
    L.sort();
    pref = [0 for i in range(N+1)]
    pref[0] = 0
    for i in range(1,N+1):
        pref[i] = pref[i-1] + L[i-1]
 
    for i in range(Q):
        K = int(raw_input())
 
        last = bisect.bisect_left(L,K)
 
        idx = binsearch(L, pref, last, K, 0, last-1)
 
        orig = max(N - last, 0)
 
        if(idx != -1):
            print orig + last - idx
        else:
            print orig

T = int(raw_input())
for i in range(T):
    n = int(raw_input())
    arr = map(int, raw_input().strip().split()) 
    asc = [1 for i in range(n)]
    for i in range(1,n):
        asc[i] = min(asc[i-1] + 1, arr[i])

    desc = [1 for i in range(n)]
    for i in reversed(range(0,n-1)):
        desc[i] = min(desc[i+1] + 1, arr[i])

    comb = [1 for i in range(n)]
    for i in range(n):
        comb[i] = min(asc[i], desc[i])
    
    max_so_far = -1
    
    peak = 0

    for i in range(n):
        if(comb[i] >= max_so_far):
            peak = i
            max_so_far = comb[i]

    start = peak - (comb[peak] - 1)
    end = peak + (comb[peak] - 1)
    
    val = [0 for i in range(n)]

    j = 1
    for i in range(start, peak):
        val[i] = j
        j += 1
    j = 1
    val[peak] = comb[peak]
    for i in reversed(range(peak+1, end+1)):
        val[i] = j
        j += 1

    sumv = 0
    for i in range(n):
        sumv += arr[i] - val[i]

    print sumv
        
            
            
                

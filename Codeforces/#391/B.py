n = input()
lst = [int(i) for i in raw_input().strip().split()]
lim = max(lst) + 1
ct = [0 for i in range(lim)]
for l in lst:
    ct[l] += 1
ret = 1
for i in range(2,lim):
    cur = 0
    for j in range(i,lim,i):
        if ct[j] > 0:
            cur += ct[j]
    ret = max(ret,cur)
print ret
            

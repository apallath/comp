n = int(raw_input())
lst = [int(i) for i in raw_input().strip().split()]
for i in range(1,n/2+1,2):
    idx = i-1
    lst[idx], lst[n-1-idx] = lst[n-1-idx], lst[idx]
print " ".join(str(i) for i in lst)
    

import math
[n,k] = map(int,raw_input().strip().split())
lst = map(int,raw_input().strip().split())
print max(0,int(math.ceil(2 * (n * (k - 0.5) - sum(lst) ) ) ) )

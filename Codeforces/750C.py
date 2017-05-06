#1900+ => div1
#1899- => div2
t = input()
upper_bound = float('inf')
lower_bound = -float('inf') #mistake made in contest - set this to 0

net_change = 0

c = 0
d = 0

for i in range(t):
    c,d = [int(j) for j in raw_input().strip().split()]    

    if d == 2:
        upper_bound = min(upper_bound, 1899 - net_change)
    if d == 1:
        lower_bound = max(lower_bound, 1900 - net_change)

    net_change += c
    
    #print upper_bound, lower_bound, upper_bound > lower_bound
if upper_bound == float('inf'):
    print "Infinity"
elif upper_bound >= lower_bound:
    print upper_bound + net_change
else:
    print "Impossible"
    
        
    

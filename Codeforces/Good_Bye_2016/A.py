i,j = map(int,raw_input().strip().split())
time = 240 - j
times = [5*t for t in range(1,i+1)]
sm = 0
ct = 0
while sm<=time and ct<len(times):    
    sm = sm + times[ct]   
    if(sm>time):
        break
    ct+=1 
print ct
    
    
    

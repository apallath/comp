inp = raw_input()
#Bulbasaur
hist  = dict()
for i in inp:
    hist[i] = hist.get(i,0) + 1
B = hist.get('B',0)
u = hist.get('u',0)//2
l = hist.get('l',0)
b = hist.get('b',0)
a = hist.get('a',0)//2
s = hist.get('s',0)
r = hist.get('r',0)
lst = min([B,u,l,b,a,s,r])
print lst
    

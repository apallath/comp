[a,b] = map(int,raw_input().strip().split())
x = 0
y = 0
x = 0
while(a / (x+1)**2 > 0):
    x+=1
y = 0
while(b / ((y+1)*(y+2)) > 0):
    y+=1
if x > y:
    print "Valera"
else:
    print "Vladik"

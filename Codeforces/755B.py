n,m = [int(i) for i in raw_input().strip().split()]

poland = 0
enemy = 0
common = 0

dictpoland = dict()

for i in range(n):
    inp = raw_input()
    poland += 1
    dictpoland[inp] = True
for i in range(m):
    inp = raw_input()
    if dictpoland.get(inp,False):
        common += 1
        poland -= 1
    else:
        enemy += 1

if poland > enemy:
    print "YES"
if poland < enemy:
    print "NO"
if poland == enemy:
    if common % 2 == 0:
        print "NO"
    else:
        print "YES"
    

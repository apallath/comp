
#   N
# W  E
#  S

#memoization is neccessary, for example, when two adjacent branches branch off such that two go into the same cell
#      O
#   OO
# O    O  <--- repeated
#   OO
#      O

memo = dict() 

d = input()
tlist = map(int,raw_input().strip().split())
dim = 2*sum(tlist)+2
cells = [[0 for i in range(dim)] for i in range(dim)]

def go(x,y,cur_fac,t_idx):   
    if memo.get((x,y,cur_fac,t_idx)) != None:
        return 0    

    if t_idx >= len(tlist):
        return 0

    xorig = x
    yorig = y

    ct = 0

    if not cells[x][y]:
        cells[x][y] = 1
        ct += 1

    if cur_fac == "N":        
        steps = tlist[t_idx]
        for i in range(steps-1):
            y+=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x-1,y+1,"NW",t_idx+1)
        ct += go(x+1,y+1,"NE",t_idx+1)

    if cur_fac == "NW":        
        steps = tlist[t_idx]
        for i in range(steps-1):
            x-=1
            y+=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x-1,y,"W",t_idx+1)
        ct += go(x,y+1,"N",t_idx+1)

    if cur_fac == "W":
        steps = tlist[t_idx]
        for i in range(steps-1):
            x-=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x-1,y+1,"NW",t_idx+1)
        ct += go(x-1,y-1,"SW",t_idx+1)

    if cur_fac == "SW":
        steps = tlist[t_idx]
        for i in range(steps-1):
            x-=1
            y-=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x-1,y,"W",t_idx+1)
        ct += go(x,y-1,"S",t_idx+1)

    if cur_fac == "S":
        steps = tlist[t_idx]
        for i in range(steps-1):
            y-=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x-1,y-1,"SW",t_idx+1)
        ct += go(x+1,y-1,"SE",t_idx+1)

    if cur_fac == "SE":
        steps = tlist[t_idx]
        for i in range(steps-1):
            x+=1
            y-=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x,y-1,"S",t_idx+1)
        ct += go(x+1,y,"E",t_idx+1)

    if cur_fac == "E":
        steps = tlist[t_idx]
        for i in range(steps-1):
            x+=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x+1,y+1,"NE",t_idx+1)
        ct += go(x+1,y-1,"SE",t_idx+1)

    if cur_fac == "NE":
        steps = tlist[t_idx]
        for i in range(steps-1):
            x+=1
            y+=1
            if not cells[x][y]:
                cells[x][y] = 1
                ct+=1
        ct += go(x,y+1,"N",t_idx+1)
        ct += go(x+1,y,"E",t_idx+1)
    
    memo[(xorig,yorig,cur_fac,t_idx)] = ct 
    #An easy mistake in memoization - forgetting that the values of x and y have changed. Took me almost an hour to figure this out! :(

    return ct

print go(dim/2, dim/2, "N", 0)


    

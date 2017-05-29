T = int(raw_input())

for t in range(T):
    n = int(raw_input())
    grid = [[] for i in range(2)]
    grid[0] = list(raw_input().strip())
    grid[1] = list(raw_input().strip())

    fromrow = 0
    fromcol = 0
    currow = 0
    curcol = 0

    repeatagain = False
    fromrowagain = 0
    fromcolagain = 0
    currowagain = 0
    curcolagain = 0

    #find starting point and from

    inithashcount = 0
    yes = False

    flag = True #in case all dots
    
    while(True):
        if(grid[0][curcol] == '.' and grid[1][curcol] == '#'):
            fromrow = 0
            fromcol = curcol
            currow = 1
            inithashcount = 1
            break
        elif(grid[0][curcol] == '#' and grid[1][curcol] == '.'):
            fromrow = 1
            fromcol = curcol
            currow = 0
            inithashcount = 1
            break
        elif(grid[0][curcol] == '#' and grid[1][curcol] == '#'):
            repeatagain = True

            fromrow = 1
            fromcol = curcol 
            currow = 0

            fromrowagain = 0
            curcolagain = curcol
            fromcolagain = curcol
            currowagain = 1

            inithashcount = 2
            break
        else:
            if(curcol < n-1):
                curcol += 1
            else:
                flag = False
                break

    if(not flag):
        print "no"
        continue          
                
    hashcount = inithashcount   
    
    while(True):
        #print currow, curcol,"from",fromrow, fromcol
        #case 1
        if((currow == 0 and curcol == fromcol and fromrow == 1) or (currow == 1 and curcol == fromcol and fromrow == 0)):
            #print "Case1"
            if(curcol != n-1):
                if(grid[currow][curcol + 1] == '#'):
                    hashcount += 1
                    fromrow, fromcol = currow, curcol
                    currow, curcol = currow, curcol + 1
                    continue
                else:
                    break
            else:
                break
        #case 2
        if(currow == 0 and currow == fromrow and curcol == fromcol + 1):
            #print "Case2"
            if(grid[1][curcol] == '#'):
                hashcount += 1
                fromrow, fromcol = currow, curcol
                currow, curcol = 1, curcol
                continue
            elif(curcol != n-1):
                if(grid[currow][curcol + 1] == '#'):
                    hashcount += 1
                    fromrow, fromcol = currow, curcol
                    currow, curcol = currow, curcol + 1
                    continue
                else:
                    break
            else:
                break
        #case 3
        if(currow == 1 and currow == fromrow and curcol == fromcol + 1):
            #print "Case3"
            if(grid[0][curcol] == '#'):
                hashcount += 1
                fromrow, fromcol = currow, curcol
                currow, curcol = 0, curcol
                continue
            elif(curcol != n-1):
                if(grid[currow][curcol + 1] == '#'):
                    hashcount += 1
                    fromrow, fromcol = currow, curcol
                    currow, curcol = currow, curcol + 1
                    continue
                else:
                    break
            else:
                break
    
    #print hashcount
    if(hashcount == grid[0].count('#') + grid[1].count('#')):            
        yes = True

    #repeat everything again!!!
    if(repeatagain):
        #print "Repeating"
        currow = currowagain
        curcol = curcolagain
        fromrow = fromrowagain
        fromcol = fromcolagain

        hashcount = inithashcount   

        while(True):
            #print currow, curcol,"from",fromrow, fromcol
            #case 1
            if((currow == 0 and curcol == fromcol and fromrow == 1) or (currow == 1 and curcol == fromcol and fromrow == 0)):
                #print "Case1"
                if(curcol != n-1):
                    if(grid[currow][curcol + 1] == '#'):
                        hashcount += 1
                        fromrow, fromcol = currow, curcol
                        currow, curcol = currow, curcol + 1
                        continue
                    else:
                        break
                else:
                    break
            #case 2
            if(currow == 0 and currow == fromrow and curcol == fromcol + 1):
                #print "Case2"
                if(grid[1][curcol] == '#'):
                    hashcount += 1
                    fromrow, fromcol = currow, curcol
                    currow, curcol = 1, curcol
                    continue
                elif(curcol != n-1):
                    if(grid[currow][curcol + 1] == '#'):
                        hashcount += 1
                        fromrow, fromcol = currow, curcol
                        currow, curcol = currow, curcol + 1
                        continue
                    else:
                        break
                else:
                    break
            #case 3
            if(currow == 1 and currow == fromrow and curcol == fromcol + 1):
                #print "Case3"
                if(grid[0][curcol] == '#'):
                    hashcount += 1
                    fromrow, fromcol = currow, curcol
                    currow, curcol = 0, curcol
                    continue
                elif(curcol != n-1):
                    if(grid[currow][curcol + 1] == '#'):
                        hashcount += 1
                        fromrow, fromcol = currow, curcol
                        currow, curcol = currow, curcol + 1
                        continue
                    else:
                        break
                else:
                    break
            
    if(hashcount == grid[0].count('#') + grid[1].count('#')):
        yes = True

    if(yes):
        print "yes"
    else:
        print "no"
    #print "\n"
            
            
        

    
        

#-------------------------------------------------------------------------------
# Name:        lcs.py
# Purpose:     Longest Common Subsequence Problem. This problem returns a LCS (there may be more than one)
#
# Author:      Akash
#
# Created:     05/03/2016
# Copyright:   (c) Akash 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def lcs(x,y):
    m=len(x)
    n=len(y)
    count=[[0 for i in range(n)] for i in range(m)] #format count[x][y]
    b=[['' for i in range(n)] for i in range(m)] #format b[x][y]
    subseq=""

    for i in range(0,m):
        for j in range(0, n):
            if x[i]==y[j]:
                count[i][j]=count[i-1][j-1]+1
                b[i][j]="DIAG"
            else:
                count[i][j]=count[i-1][j]
                b[i][j]="UP"
                if count[i][j-1]>count[i][j]:
                    count[i][j]=count[i][j-1]
                    b[i][j]="LEFT"

    while not (i<0 or j<0):
        if b[i][j]=="DIAG":
            subseq=x[i]+subseq
            i-=1
            j-=1
        elif b[i][j]=="UP":
            i-=1
        else:
            j-=1

    return subseq


print lcs("hieroglyphology", "michaelangelo")
print lcs("AGGTAB", "GXTXAYB")

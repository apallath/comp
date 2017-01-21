#-------------------------------------------------------------------------------
# Name:        parenthesization.py
# Purpose:     To parenthesize a sequence of matrix multiplications in order to
#              reduce the time required for matrix multiplication
#
# Author:      Akash
#
# Created:     05/03/2016
# Copyright:   (c) Akash 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------
from collections import deque

def multcost(lst1, lst2):
    if lst1[len(lst1)-1][1]==lst2[0][0]:
        return lst1[0][0]*lst2[len(lst2)-1][1]
    raise ValueError('Incorrect Multiplication!! Dimension Mismatch!!')

def parenthesize(A):
    n=len(A)
    cost={}
    parent={}
    for i in range(1,n+1):
        cost[i-1,i]=0

    for j in range(2,n+1):
        for i in range(0, n-j+1):
            for k in range(i+1, i+j):
                if cost[i,k]+cost[k,i+j]+multcost(A[i:k],A[k:i+j]) <= cost.get((i,i+j), cost[i,k]+cost[k,i+j]+multcost(A[i:k],A[k:i+j])):
                    cost[i,i+j]=cost[i,k]+cost[k,i+j]+multcost(A[i:k],A[k:i+j])
                    parent[(i,i+j)]=k
            #cost[i,i+j]=min([(cost[i,k]+cost[k,i+j]+multcost(A[i:k],A[k:i+j])) for k in range(i+1, i+j)])
    return cost, parent

if __name__ == '__main__':
    #DEBUG1 print multcost([(2,2),(2,3),(3,4),(4,5)],[(5,2),(2,3)])
    A=[(10,1),(1,10),(10,1)]
    print parenthesize(A)
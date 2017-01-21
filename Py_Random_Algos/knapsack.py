#-------------------------------------------------------------------------------
# Name:        knapsack.py
# Purpose:     Solution to the Knapsack Problem
#
# Author:      Akash
#
# Created:     05/03/2016
# Copyright:   (c) Akash 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def knapsack(val, size, S, n):
    bag_value=[[0 for i in range(S+1)] for i in range(n+1)]
    item_included=[[False for i in range(S+1)] for i in range(n+1)]

    for i in reversed(range(n)):
        for s in range(S+1):
            if size[i]<=s:
                notinc=bag_value[i+1][s]
                inc=bag_value[i+1][s-size[i]]+val[i]
                if inc>=notinc:
                    bag_value[i][s]=inc
                    item_included[i][s]=True
                elif inc<notinc:
                    bag_value[i][s]=notinc

    return bag_value[0][S]

# Driver program to test above function
val = [8,4,0,5,3]
wt = [1,2,3,2,2]
W = 4
n = len(val)
print(knapsack(val, wt, W, n))


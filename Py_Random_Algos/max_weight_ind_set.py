#-------------------------------------------------------------------------------
# Name:        Max_Weight_Independent_Set
# Purpose:     To find the weight of a maximum weight independent set given a tree with weights on the vertices
#
# Author:      Akash
#
# Created:     02/04/2016
# Copyright:   (c) Akash 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

#Using Erik Demaine's version of BFS Algorithm for the BFS part of the program. Modified for Trees.
#No need to check if vertex has already been seen or not. It's a TREE. It obviously hasn't been seen before.
#Tree representation using adjacency list. Probably not very conventional.

class VertexErik:
    def __init__(self, value):
        self.value=value
    def __repr__(self):
        return self.value

def ErikBFS(root, Adj):
    level={root:0}
    children={root:None}

    i=1 #Next level
    frontier=[root] #Vertices in the previous level

    while frontier:
        nextfrontier=[] #Vertices in the next level, i.e. i
        for u in frontier:
            for v in Adj[u]:
                level[v]=i
                if children.get(u) is not None:
                    children.get(u).append(v)
                else:
                    children[u]=[v]
                nextfrontier.append(v)
        frontier=nextfrontier
        i+=1
    return level, children

def MWIS(root, Adj, children, weight):
    A=dict()
    B=dict()
    lst=reversed([i for i in level.keys()].sort())
    for i in lst:
        for v in level[i]:
            if children.get(v) is None:
                A[v]=weight[v]
                B[v]=0
            else:
                sigmaBchild=sum([B[u] for u in children.get(v)])
                sigmaAchild=sum([A[u] for u in children.get(v)])
                A[v]=sigmaBchild+weight[v]
                B[v]=max(sigmaBchild, sigmaAchild)

    return max(A[root], B[root])



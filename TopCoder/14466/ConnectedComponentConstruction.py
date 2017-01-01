class ConnectedComponentConstruction:
    def construct(self, s):
        m = len(s)
        retl = [["N" for i in range(m)] for i in range(len(s))]
        lst = [[] for i in range(len(s)+1)]
        for index, j in enumerate(s):
            if j > len(s):
                return tuple([])
            lst[j].append(index)
        for i in range(2,len(lst)):
            if len(lst[i]) > 0 and len(lst[i])%i != 0:
                return tuple([])
            for c in range(len(lst[i])/i):
                comp = lst[i][i*c:i*c+i]
                for p in range(len(comp)):
                    u = comp[p]
                    v = comp[p-1]
                    retl[u][v] = "Y"
                    retl[v][u] = "Y"
        newret = ["".join(i) for i in retl]
        return tuple(newret)

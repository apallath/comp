class SwapAndArithmetic:
    def able(self, x):
        lst = list(x)
        for i in range(1,len(lst)):
            lst[i] = lst[i]-lst[0]
        lst[0] = 0
        lst.sort()
        diff = lst[1] - lst[0]
        for i in range(1,len(lst)):
            if lst[i] - lst[i-1] != diff:
                return "Impossible"
        return "Possible"
            

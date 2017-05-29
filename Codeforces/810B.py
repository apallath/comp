[n,f] = map(int,raw_input().strip().split())
k = [0 for i in range(n)]
l = [0 for i in range(n)]
sell = [0 for i in range(n)]
sellout = [0 for i in range(n)]
extra = [0 for i in range(n)]
for i in range(n):
    k[i],l[i] = map(int,raw_input().strip().split())
    sell[i] = min(k[i], l[i])
    sellout[i] = min(2 * k[i], l[i])
    extra[i] = sellout[i] - sell[i]
extra.sort(reverse=True)
curtot = sum(sell)
extratot = sum(extra[0:f])
print curtot + extratot

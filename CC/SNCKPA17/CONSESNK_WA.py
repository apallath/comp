T = int(raw_input())
for i in range(T):
    N, L, A, B = map(int, raw_input().strip().split())
    S = map(int,raw_input().strip().split())       
    S.sort()
    F = [i for i in S]     
    if F[0] < A:
        F[0] = A
    for i in range(1,N):
        F[i] = F[i-1] + L   
    shiftback = 0
    if F[N-1] + L > B:
        shiftback = (F[N-1] + L) - B
    for i in range(N):
        F[i] -= shiftback
    cost = 0
    for i in range(N):
        cost += abs(F[i] - S[i])
    assert(F[0] >= A)
    assert(F[N-1] <= B)
    for i in range(1,N):
        assert(F[i] - F[i-1] == L)
    print cost    
        
        
    

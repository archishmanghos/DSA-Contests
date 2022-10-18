def downwardDigonal(N, A): 
    ans, j, idx = [None for i in range(N * N)], 0, 0
    for i in range(2 * N):
        if i == N: continue
        k, l = 0 if i < N else i % N, j
        while k < N and l >= 0:
            ans[idx] = A[k][l]
            idx, k, l = idx + 1, k + 1, l - 1    
            
        j = j if j == N - 1 else j + 1
    
    return ans
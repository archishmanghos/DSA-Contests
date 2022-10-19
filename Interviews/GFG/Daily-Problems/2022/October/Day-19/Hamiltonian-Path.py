class Solution:
    def check(self, N, M, Edges): 
        adj, cache = [[False for i in range(N)] for j in range(N)], [[False for i in range(1 << N)] for j in range(N)]
        for e in Edges:
            adj[e[0] - 1][e[1] - 1] = adj[e[1] - 1][e[0] - 1] = True
        for i in range(N):
            cache[i][1 << i] = True
        
        for i in range(1 << N):
            for j in range(N):
                if ((i >> j) & 1):
                    for k in range(N):
                        if j != k and (i >> k) & 1 and adj[j][k] and cache[k][i ^ (1 << j)]:
                            cache[j][i] = True
                            break
        
        for i in range(N):
            if cache[i][(1 << N) - 1]:
                return True
        
        return False
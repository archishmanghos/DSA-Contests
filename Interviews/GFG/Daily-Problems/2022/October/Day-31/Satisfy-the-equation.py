class Solution:
    def satisfyEqn (self, A, N):
        ump, ans = {}, [-1, -1, -1, -1]
        for i in range(N - 1):
            for j in range(i + 1, N):
                x = A[i] + A[j]
                if x in ump:
                    if ump[x][0] == i or ump[x][1] == i or ump[x][0] == j or ump[x][1] == j: continue
                    v = [ump[x][0], ump[x][1], i, j]
                    if ans[0] == -1 or v < ans:
                        ans = v
                else:
                    ump[x] = [i, j]
        
        return ans
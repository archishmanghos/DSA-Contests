class Solution:
    def dp(self, idx, d, maxWork, jd, cache) -> int:
        if idx == len(jd):
            if d > 0: return 1e9
            return maxWork
        if cache[idx][d][maxWork] != -1:
            return cache[idx][d][maxWork]
        
        ans = self.dp(idx + 1, d, max(maxWork, jd[idx]), jd, cache)
        if d > 0:
            ans = min(ans, self.dp(idx + 1, d - 1, jd[idx], jd, cache) + maxWork)
            
        cache[idx][d][maxWork] = ans
        return ans
    
    def minDifficulty(self, jD: List[int], d: int) -> int:
        n = len(jD)
        cache = [[[-1 for i in range(1001)] for j in range(d)] for k in range(n)]
        ans = self.dp(1, d - 1, jD[0], jD, cache)
        if ans == 1e9:
            return -1
        return ans
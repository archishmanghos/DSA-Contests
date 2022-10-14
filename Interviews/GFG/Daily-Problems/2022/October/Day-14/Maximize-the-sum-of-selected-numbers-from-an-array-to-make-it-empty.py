class Solution:
    def maximizeSum (self, arr, n) : 
        mark, ans, maxx = [0 for i in range(100001)], 0, 0
        for i in arr:
            mark[i] += 1
            maxx = max(maxx, i)
        
        for i in range(maxx, 0, -1):
            ans += mark[i] * i
            mark[i - 1] = max(mark[i - 1] - mark[i], 0)
        
        return ans
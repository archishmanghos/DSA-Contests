class Solution:
    def findSum(self, A, N): 
        maxx, minn = int(-1e10), int(1e10)
        for x in A:
            maxx = max(maxx, x)
            minn = min(minn, x)
        
        return maxx + minn;
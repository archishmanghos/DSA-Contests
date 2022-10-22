class Solution:
    def fillingBucket(self, N):
        cur, pre, prepre, mod = 0, 0, 0, int(1e8)
        for i in range(N + 1):
            if i == 0: cur = 1
            else:
                cur = (cur + pre) % mod
                if i > 1:
                    cur = (cur + prepre) % mod
            prepre = pre
            pre = cur
            cur = 0
        
        return pre
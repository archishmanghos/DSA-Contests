class Solution:
    def countSubarray(self, arr, n, k):
        ans, maxx = 0, [0, -1]
        for idx, i in enumerate(arr):
            if i > k:
                maxx = [i, idx]
            ans += maxx[-1] + 1
        return ans

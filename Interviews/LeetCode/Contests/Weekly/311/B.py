class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            k, j, cnt = i, ord(s[i]), 0
            while k < n and j < 123:
                ans = max(ans, cnt)
                if(ord(s[k]) != j): break
                j += 1
                k += 1
                cnt += 1
            ans = max(ans, cnt)
        return ans
class Solution:
    def countOfSubstrings(self, s, k):
        n, ans , extra, cnt = len(s), 0, 0, [0] * 26
        
        for i in range(n):
            if cnt[ord(s[i]) - 97] > 0: extra += 1
            cnt[ord(s[i]) - 97] += 1
            
            if i >= k - 1:
                if extra == 1: ans += 1
                if (cnt[ord(s[i - k + 1]) - 97] > 1): extra -= 1
                cnt[ord(s[i - k + 1]) - 97] -= 1
        
        return ans
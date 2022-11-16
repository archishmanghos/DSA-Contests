class Solution:
    def beautySum(self, s):
        ans = 0
        for idx, i in enumerate(s):
            cnt = [0 for i in range(26)]
            for j in range(idx, len(s)):
                cnt[ord(s[j]) - 97] += 1
                maxx, minn = 0, 1000
                for k in range(26):
                    maxx = max(maxx, cnt[k])
                    if cnt[k] > 0:
                        minn = min(minn, cnt[k])
                ans += maxx - minn
        return ans

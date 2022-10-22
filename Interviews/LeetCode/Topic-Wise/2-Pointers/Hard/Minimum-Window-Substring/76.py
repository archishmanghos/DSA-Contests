class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cnt = [0 for i in range(58)]
        for c in t: cnt[ord(c) - 65] += 1
        
        dist, start, i = int(1e9), -1, 0
        for j, ch in enumerate(s):
            cnt[ord(ch) - 65] -= 1
            while i < len(s) and cnt[ord(s[i]) - 65] < 0:
                cnt[ord(s[i]) - 65] += 1
                i += 1
            
            ok = True
            for k in cnt: ok &= k <= 0
            
            if ok and dist > (j - i + 1):
                dist, start = j - i + 1, i
        
        return "" if dist > len(s) else s[start : start + dist]
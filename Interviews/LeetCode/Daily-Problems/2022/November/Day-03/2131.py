class Solution:
    def longestPalindrome (self, words: List[str]) -> int:
        ump, ans, countPal = {}, 0, 0
        for s in words: ump[s] = ump.get(s, 0) + 1
        
        for s in words:
            if ump[s] > 0:
                t = s[::-1]
                if (t in ump and ((s != t and ump[t] > 0) or (s == t and ump[t] > 1))):
                    minCanTake = min(ump[s], ump[t])
                    if s == t: minCanTake //= 2
                    ans += minCanTake * 2 * 2
                    ump[s] -= minCanTake
                    ump[t] -= minCanTake
            if ump[s] > 0 and s[0] == s[1]:
                countPal += 1
        
        return ans + (2 if countPal else 0)
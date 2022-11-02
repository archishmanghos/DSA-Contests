class Solution:
    def countSteps (self, s, end, ump) -> int:
        if s == end: return 0
        ch, ans = ['A', 'C', 'T', 'G'], int(1e5)
        
        for i in range(8):
            for j in range(4):
                if s[i] != ch[j]:
                    t = s[:i] + ch[j] + ("" if i == 7 else s[i + 1:])
                    if t in ump and ump[t] == 1:
                        ump[t] = 0
                        ans = min(ans, self.countSteps(t, end, ump) + 1)
                        ump[t] = 1
        
        return ans
    
    def minMutation (self, start: str, end: str, bank: List[str]) -> int:
        ump = {}
        for s in bank: ump[s] = 1
        ans = self.countSteps(start, end, ump)
        return -1 if ans > 10 else ans
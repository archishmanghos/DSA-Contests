class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for s in queries:
            for t in dictionary:
                change = 0
                for i in range(len(t)):
                    if t[i] != s[i]:
                        change += 1
                if change <= 2:
                    ans.append(s)
                    break
        
        return ans
class Solution:
    def groupAnagrams (self, strs: List[str]) -> List[List[str]]:
        ump, ans = {}, []
        for s in strs:
            t = ''.join(sorted(s))
            if t not in ump:
                temp = []
                temp.append(s)
                ump[t] = temp
            else:
                temp = ump.get(t)
                temp.append(s)
                ump[t] = temp
        for value in ump.values():
            temp = []
            for s in value:
                temp.append(s)
            ans.append(temp)
        
        return ans
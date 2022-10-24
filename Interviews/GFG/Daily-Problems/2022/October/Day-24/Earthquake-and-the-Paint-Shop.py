class alphanumeric:
    def __init__ (self, name, count):
        self.name = name
        self.count = count
class Solution:
    def sortedStrings(self, N, A):
        mp, ans = {}, []
        for s in A:
            mp[s] = mp.get(s, 0) + 1
        for key in sorted(mp.keys()):
            ans.append(alphanumeric(key, mp[key]))
        
        return ans
class Solution:
    def removeDuplicates(self, s: str) -> str:
        ans = []
        for c in s:
            if len(ans) and ans[-1] == c:
                while ans and ans[-1] == c:
                    ans.pop()
            else:
                ans.append(c)
        
        return "".join(ans)
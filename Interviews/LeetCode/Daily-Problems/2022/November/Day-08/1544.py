class Solution:
    def makeGood(self, s: str) -> str:
        ans = []
        for c in s:
            if len(ans) == 0 or abs(ord(c) - ord(ans[-1])) != 32:
                ans.append(c)
            else:
                ans.pop()

        return "".join(ans)

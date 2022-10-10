class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        ans, done, i, j = list(palindrome), False, 0, len(palindrome) - 1
        while i < j:
            if ans[i] != 'a':
                ans[i], done = 'a', True
                break
            i, j = i + 1, j - 1
        
        if not done:
            if len(palindrome) > 1: ans[-1] = 'b'
            else: ans = []
        
        return "".join(ans)
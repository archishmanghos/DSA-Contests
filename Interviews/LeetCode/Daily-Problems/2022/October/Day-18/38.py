class Solution:
    def convertToShit(self, s: string) -> str:
        cnt, ans, cur = 0, "", s[0]
        for i in s:
            if i == cur:
                cnt += 1
            else:
                ans += str(cnt) + cur
                cur, cnt = i, 1
        
        return ans
    
    def countAndSay(self, n: int) -> str:
        ans = "1"
        for i in range(1, n):
            ans = self.convertToShit(ans + 'a')
        return ans
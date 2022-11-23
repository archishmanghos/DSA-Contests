class Solution:
    def maxSumLCM(self, n):
        ans, i = 0, 1
        while i * i <= n:
            if n % i == 0:
                ans += i
                if n // i != i:
                    ans += n // i
            i += 1

        return ans

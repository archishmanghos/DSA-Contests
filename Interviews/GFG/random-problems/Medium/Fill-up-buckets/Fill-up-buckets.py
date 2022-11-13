class Solution:
    def totalWays(self, n, capacity):
        k, mod, ans = 0, int(1e9 + 7), 1
        for i in sorted(capacity):
            ans = (ans * (i - k)) % mod
            k += 1
        return ans

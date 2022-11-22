class Solution:
    def numSquares(self, n: int) -> int:
        sq = math.isqrt(n)
        cache = [0 for i in range(n + 1)]
        for i in range(1, n + 1):
            cache[i] = int(1e9)
            for j in range(1, sq + 1):
                if j * j <= i:
                    cache[i] = min(cache[i], cache[i - j * j] + 1)

        return cache[n]

# This solution TLEs on LeetCode. The same solution as the C++ version.

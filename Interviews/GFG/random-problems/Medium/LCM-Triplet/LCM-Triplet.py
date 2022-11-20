import math


class Solution:
    def lcmTriplets(self, N):
        if N % 6 == 0:
            return (N - 1) * (N - 2) * (N - 3)
        if N <= 2:
            return N

        ans = N * (N - 1)
        for i in range(N - 2, 0, -1):
            if math.gcd(ans, i) == 1:
                ans *= i
                break

        return ans

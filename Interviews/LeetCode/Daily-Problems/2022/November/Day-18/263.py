class Solution:
    def isUgly(self, n: int) -> bool:
        primes = [2, 3, 5]
        for i in primes:
            while n > 1 and n % i == 0:
                n //= i
        return n == 1

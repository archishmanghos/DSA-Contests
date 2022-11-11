class Solution:
    def isPrime(self, N) -> bool:
        i = 2
        while i * i <= N:
            if N % i == 0:
                return False
            i += 1
        return True

    def isSumOfTwo(self, N):
        for i in range(2, N):
            if self.isPrime(i) and self.isPrime(N - i):
                return "Yes"

        return "No"

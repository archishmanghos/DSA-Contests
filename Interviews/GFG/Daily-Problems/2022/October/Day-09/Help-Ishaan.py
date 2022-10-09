import math

class Solution:
    def isPrime(self, N) -> bool:
        if (N <= 1): return False
        for i in range(2, int(math.sqrt(N)) + 1):
            if N % i == 0:
                return False
        
        return True
        
	def NthTerm(self, N):
	    i = 0
	    while i >= 0:
	        if self.isPrime(N + i) or self.isPrime(N - i):
	            return i
	        i += 1
	            
	    return -1

class Solution:
	def NthTerm(self, n):
		ans, mod = 1, int(1e9 + 7)
		for i in range(n):
		    ans = ((ans * (i + 1)) + 1) % mod
		return ans
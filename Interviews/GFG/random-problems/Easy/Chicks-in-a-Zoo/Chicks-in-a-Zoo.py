class Solution:
	def NoOfChicks (self, N):
		dp, ans = [1 for i in range(N)], 1
		for i in range(1, N):
		    if i >= 6: ans -= dp[i - 6]
		    dp[i] = ans * 2
		    ans += ans * 2
		
		return ans
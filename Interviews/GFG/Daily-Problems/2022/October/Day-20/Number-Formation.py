class Solution:
	def getSum(self, x, y, z):
		exactsum = [[[0 for i in range(z + 1)] for j in range(y + 1)] for k in range(x + 1)]
		exactnum = [[[0 for i in range(z + 1)] for j in range(y + 1)] for k in range(x + 1)]
        ans, exactnum[0][0][0], mod = 0, 1, int(1e9 + 7)
        
        for i in range(x + 1):
            for j in range(y + 1):
                for k in range(z + 1):
                    if i > 0:
                        exactsum[i][j][k] += (exactsum[i - 1][j][k] * 10 + 4 * exactnum[i - 1][j][k]) % mod;
                        exactnum[i][j][k] += exactnum[i - 1][j][k] % mod;
                        exactsum[i][j][k] %= mod;
                    if j > 0:
                        exactsum[i][j][k] += (exactsum[i][j - 1][k] * 10 + 5 * exactnum[i][j - 1][k]) % mod;
                        exactnum[i][j][k] += exactnum[i][j - 1][k] % mod;
                        exactsum[i][j][k] %= mod;
                    if k > 0:
                        exactsum[i][j][k] += (exactsum[i][j][k - 1] * 10 + 6 * exactnum[i][j][k - 1]) % mod;
                        exactnum[i][j][k] += exactnum[i][j][k - 1] % mod;
                        exactsum[i][j][k] %= mod;
                    ans = (ans + exactsum[i][j][k]) % mod
        
        return int(ans)
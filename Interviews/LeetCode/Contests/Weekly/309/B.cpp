int dp(int startPos, int k, int endPos, vector<vector<int>> &cache, int mod = 1e9 + 7) {
	if (k == 0) return startPos == endPos;
	if (cache[startPos][k] != -1) return cache[startPos][k];

	int ans = (dp(startPos + 1, k - 1, endPos, cache) % mod + dp(startPos - 1, k - 1, endPos, cache) % mod) % mod;
	return cache[startPos][k] = ans;
}
int numberOfWays(int startPos, int endPos, int k) {
	int toAdd = abs(min(0, min(startPos - k, endPos - k)));
	startPos += toAdd, endPos += toAdd;
	vector<vector<int>> cache(5000, vector<int>(5000, -1));

	return dp(startPos, k, endPos, cache);
}
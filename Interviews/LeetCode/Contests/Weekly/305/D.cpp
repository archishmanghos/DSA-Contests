int longestIdealString(string s, int k) {
	int n = s.size();
	vector<vector<int>> cache(n + 1, vector<int>(27, 0));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 26; j >= 0; j--) {
			int curChar = (s[i] - 'a') + 1;
			cache[i][j] = cache[i + 1][j];
			if (j == 0 or abs(curChar - j) <= k) {
				cache[i][j] = max(cache[i][j], cache[i + 1][curChar] + 1);
			}
		}
	}

	return cache[0][0];
}
vector<int> numberOfPairs(vector<int>& nums) {
	vector<int> cnt(102, 0);
	for (int i : nums) {
		cnt[i] += 1;
	}

	int ans = 0;
	for (int i = 0; i <= 100; i++) ans += cnt[i] / 2;

	return {ans, (int)nums.size() - ans * 2};
}
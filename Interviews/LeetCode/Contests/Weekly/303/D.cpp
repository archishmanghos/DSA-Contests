int setBitCount(int n) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		if ((n >> i) & 1) {
			ans += 1;
		}
	}

	return ans;
}
long long countExcellentPairs(vector<int>& nums, int k) {
	vector<int> setBits(32, 0);
	sort(nums.begin(), nums.end());
	auto newSize = unique(nums.begin(), nums.end());
	nums.resize(distance(nums.begin(), newSize));
	long long ans = 0, n = nums.size();

	for (int i = 0; i < n; i++) {
		setBits[setBitCount(nums[i])] += 1;
	}

	for (int i = 30; i >= 0; i--) {
		setBits[i] += setBits[i + 1];
	}

	for (int i = 0; i < n; i++) {
		int bitsRequired = max(0LL, k - 1LL * setBitCount(nums[i]));
		if (bitsRequired <= 31) {
			ans += setBits[bitsRequired];
		}
	}

	return ans;
}
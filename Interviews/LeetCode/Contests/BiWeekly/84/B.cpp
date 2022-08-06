long long countBadPairs(vector<int>& nums) {
	int n = nums.size();
	vector<long long> diffArr(n, 0);
	for (int i = 0; i < n; i++) {
		diffArr[i] = nums[i] - i;
	}

	map<long long, long long> cnt;
	cnt[diffArr[n - 1]] += 1;
	long long ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		long long pairs = n - 1 - i;
		if (cnt.find(diffArr[i]) != cnt.end()) {
			pairs -= cnt[diffArr[i]];
		}

		cnt[diffArr[i]] += 1;
		ans += pairs;
	}

	return ans;
}
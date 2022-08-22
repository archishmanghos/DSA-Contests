bool validPartition(vector<int>& nums) {
	int n = nums.size();
	vector<int> cache(n + 1, 0);
	cache[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		if (i + 1 < n) {
			if (nums[i] == nums[i + 1]) {
				cache[i] |= cache[i + 2];
			}
		}
		if (i + 2 < n) {
			if ((nums[i] == nums[i + 1] and nums[i + 1] == nums[i + 2]) or (nums[i] + 1 == nums[i + 1] and nums[i + 1] + 1 == nums[i + 2])) {
				cache[i] |= cache[i + 3];
			}
		}
	}

	return cache[0];
}
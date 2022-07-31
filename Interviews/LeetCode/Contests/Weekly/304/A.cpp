int minimumOperations(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int ans = 0;
	while (nums.back() != 0) {
		int minn = 0;
		ans += 1;
		for (int i : nums) {
			if (i > 0) {
				minn = i;
				break;
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			nums[i] -= minn;
		}
		sort(nums.begin(), nums.end());
	}

	return ans;
}
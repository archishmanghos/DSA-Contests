long long minimumReplacement(vector<int>& nums) {
	int n = nums.size();
	long long ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (nums[i] > nums[i + 1]) {
			long long parts = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
			ans += max(0LL, parts - 1);
			nums[i] = (nums[i] / parts);
		}
	}

	return ans;
}
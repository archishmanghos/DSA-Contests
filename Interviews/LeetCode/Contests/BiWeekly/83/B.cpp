long long zeroFilledSubarray(vector<int>& nums) {
	long long ans = 0, n = nums.size(), cnt = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) cnt += 1, ans += cnt;
		else cnt = 0;
	}

	return ans;
}
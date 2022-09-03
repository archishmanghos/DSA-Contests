bool findSubarrays(vector<int>& nums) {
	vector<int> v;
	for (int i = 0; i < nums.size() - 1; i++) {
		int sum = 0;
		for (int j = i; j <= (i + 1); j++) {
			sum += nums[j];
		}
		v.push_back(sum);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) return true;
	}

	return false;
}
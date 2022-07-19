int getSum(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}

	return ans;
}
int maximumSum(vector<int>& nums) {
	vector<priority_queue<int>> cntFreq(102);
	for (int i : nums) {
		int digitSum = getSum(i);
		cntFreq[digitSum].push(i);
	}

	int ans = -1;
	for (int i = 1; i <= 100; i++) {
		if (cntFreq[i].size() > 1) {
			int large = cntFreq[i].top();
			cntFreq[i].pop();
			int nextlarge = cntFreq[i].top();
			ans = max(ans, large + nextlarge);
		}
	}

	return ans;
}
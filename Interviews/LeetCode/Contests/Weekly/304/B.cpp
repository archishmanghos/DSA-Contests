int maximumGroups(vector<int>& grades) {
	int n = grades.size(), ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i * (i + 1) / 2 > n) break;
		ans = i;
	}
	return ans;
}
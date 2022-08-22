int minimumRecolors(string blocks, int k) {
	int n = blocks.size(), ans = 0;
	for (int i = 0; i < k; i++) {
		ans += blocks[i] == 'W';
	}

	int now = ans;
	for (int i = k; i < n; i++) {
		now -= blocks[i - k] == 'W';
		now += blocks[i] == 'W';
		ans = min(ans, now);
	}

	return ans;
}
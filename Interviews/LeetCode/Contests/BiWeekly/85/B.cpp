bool check(string s) {
	if (s.size() == 1) return false;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1' and s[i - 1] == '0') return true;
	}

	return false;
}
int secondsToRemoveOccurrences(string s) {
	int ans = 0;
	while (check(s)) {
		ans += 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '1' and s[i - 1] == '0') {
				swap(s[i], s[i - 1]);
				i += 1;
			}
		}
	}

	return ans;
}
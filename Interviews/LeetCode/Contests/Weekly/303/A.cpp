char repeatedCharacter(string s) {
	vector<int> cnt(26, 0);
	for (char c : s) {
		if (cnt[c - 'a'] == 1) return c;
		cnt[c - 'a'] += 1;
	}
	return '0';
}
string removeStars(string s) {
	int n = s.size(), cntStars = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != '*') {
			if (cntStars) {
				s[i] = '*';
				cntStars--;
			}
		} else {
			cntStars += 1;
		}
	}

	string ans = "";
	for (char c : s) {
		if (c != '*') ans += c;
	}

	return ans;
}
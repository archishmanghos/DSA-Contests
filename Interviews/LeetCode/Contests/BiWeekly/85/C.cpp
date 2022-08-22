string shiftingLetters(string s, vector<vector<int>>& shifts) {
	int n = s.size();
	vector<int> pref(n + 1, 0);
	for (auto i : shifts) {
		int l = i[0], r = i[1], d = i[2];
		if (d == 0) {
			pref[l] -= 1;
			pref[r + 1] += 1;
		} else {
			pref[l] += 1;
			pref[r + 1] -= 1;
		}
	}

	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
	}

	for (int i = 0; i < n; i++) {
		if (pref[i] < 0) {
			int shift = abs(pref[i]) % 26;
			if (shift > (s[i] - 'a')) {
				s[i] = (((s[i] - 'a') + (26 - shift)) + 'a');
			} else {
				s[i] = (s[i] - shift);
			}
		} else {
			int shift = pref[i] % 26;
			if (shift > (25 - (s[i] - 'a'))) {
				s[i] = (((s[i] - 'a') - (26 - shift)) + 'a');
			} else {
				s[i] = (s[i] + shift);
			}
		}
	}

	return s;
}
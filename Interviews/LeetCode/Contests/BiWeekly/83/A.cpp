string bestHand(vector<int>& ranks, vector<char>& suits) {
	vector<int> cnt1(15, 0), cnt2(4, 0);
	for (int i : ranks) cnt1[i] += 1;
	for (char c : suits) cnt2[c - 'a'] += 1;

	for (int i = 0; i < 4; i++) {
		if (cnt2[i] == 5) return "Flush";
	}

	for (int i = 1; i <= 13; i++) {
		if (cnt1[i] >= 3) return "Three of a Kind";
	}

	for (int i = 1; i <= 13; i++) {
		if (cnt1[i] >= 2) return "Pair";
	}

	return "High Card";
}
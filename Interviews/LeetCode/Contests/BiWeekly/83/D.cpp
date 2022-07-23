int shortestSequence(vector<int>& rolls, int k) {
	set<int> s;
	int cur = 1, ans = 1;
	for (int i = 0; i < rolls.size(); i++) {
		if (cur) {
			s.insert(rolls[i]);
			if (s.size() == k) {
				ans += 1;
				cur ^= 1;
			}
		} else {
			s.erase(rolls[i]);
			if (s.size() == 0) {
				ans += 1;
				cur ^= 1;
			}
		}
	}

	return ans;
}
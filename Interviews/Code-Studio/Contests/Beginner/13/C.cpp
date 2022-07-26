int mex(vector<int> a, int k) {
	set<int> s;
	map<int, int> mp;
	for (int i = 0; i < a.size(); i++) {
		a[i] %= k;
		s.insert(a[i]);
		mp[a[i]] += 1;
	}

	int ans = 0, minCount = INT_MAX;
	for (int i = 0; i < k; i++) {
		if (s.find(i) == s.end()) {
			return i;
		}
		minCount = min(minCount, mp[i]);
	}

	return (k - 1) + minCount * k;
}
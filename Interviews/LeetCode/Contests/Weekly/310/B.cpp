int partitionString(string s) {
	set<int> st;
	int ans = 1;
	for (int i = 0; i < s.size(); i++) {
		if (st.find(s[i]) != st.end()) {
			ans += 1;
			st.clear();
		}
		st.insert(s[i]);
	}

	return ans;
}
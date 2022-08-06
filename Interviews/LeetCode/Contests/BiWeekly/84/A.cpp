vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
	vector<vector<int>> ans;
	vector<bool> done(1005, false);
	for (auto i : items1) {
		int value = i[0], weight = i[1];
		for (auto j : items2) {
			if (j[0] == value) {
				weight += j[1];
			}
		}
		done[value] = true;

		ans.push_back({value, weight});
	}

	for (auto i : items2) {
		int value = i[0], weight = i[1];
		if (done[value]) continue;
		for (auto j : items1) {
			if (j[0] == value) {
				weight += j[1];
			}
		}
		done[value] = true;
		ans.push_back({value, weight});
	}

	sort(ans.begin(), ans.end());
	return ans;
}
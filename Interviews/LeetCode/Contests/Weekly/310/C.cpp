int minGroups(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	multiset<int> groups;
	groups.insert(intervals[0][1]);
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] <= (*groups.begin())) {
			groups.insert(intervals[i][1]);
		} else {
			auto it = groups.lower_bound(intervals[i][0]);
			it--;
			int toErase = *it;
			groups.erase(groups.find(toErase));
			groups.insert(intervals[i][1]);
		}
	}

	return groups.size();
}
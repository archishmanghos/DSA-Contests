vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
	int n = nums.size(), j = 0;
	set<pair<int, int>> intervals;
	multiset<int64_t> segmentSums;
	vector<int64_t> prefSum(n, nums[0]);
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + nums[i];
	}

	intervals.insert({0, n - 1});
	segmentSums.insert(prefSum[n - 1]);

	vector<long long> ans(removeQueries.size());
	for (int q : removeQueries) {
		auto it = intervals.upper_bound({q, 1e9});
		it--;
		pair<int, int> interval = *it;
		int64_t sumPresent = prefSum[interval.second] - (interval.first > 0 ? prefSum[interval.first - 1] : 0);

		pair<int, int> newInterval1 = { -1, -1}, newInterval2 = { -1, -1};
		if (interval.first < q) newInterval1 = {interval.first, q - 1};
		if (interval.second > q) newInterval2 = {q + 1, interval.second};

		intervals.erase(it);
		segmentSums.erase(segmentSums.find(sumPresent));

		if (newInterval1.first != -1) {
			int64_t newSum = prefSum[newInterval1.second] - (newInterval1.first > 0 ? prefSum[newInterval1.first - 1] : 0);
			intervals.insert(newInterval1);
			segmentSums.insert(newSum);
		}

		if (newInterval2.first != -1) {
			int64_t newSum = prefSum[newInterval2.second] - (newInterval2.first > 0 ? prefSum[newInterval2.first - 1] : 0);
			intervals.insert(newInterval2);
			segmentSums.insert(newSum);
		}

		ans[j++] = (segmentSums.size() ? *segmentSums.rbegin() : 0);
	}

	return ans;
}
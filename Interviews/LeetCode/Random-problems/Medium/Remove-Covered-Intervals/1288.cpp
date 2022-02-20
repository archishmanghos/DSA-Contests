int removeCoveredIntervals(vector <vector<int>> &intervals) {
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    };

    sort(intervals.begin(), intervals.end(), cmp);

    int ans = 0, end = -1;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] > end) {
            ans += 1;
            end = intervals[i][1];
        } else {
            if (intervals[i][1] > end) {
                end = intervals[i][1];
                ans += 1;
            }
        }
    }

    return ans;
}
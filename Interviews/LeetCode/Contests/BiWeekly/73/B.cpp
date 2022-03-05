vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    };
    vector <pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i], j = 1, newN = 0;
        if (x == 0) {
            newN += mapping[0];
        } else {
            while (x > 0) {
                newN += (mapping[x % 10]) * j;
                x /= 10;
                j *= 10;
            }
        }
        ans.push_back({newN, i});
    }

    sort(ans.begin(), ans.end(), cmp);
    vector<int> finalAns;
    for (int i = 0; i < nums.size(); i++) {
        finalAns.push_back(nums[ans[i].second]);
    }
    return finalAns;
}
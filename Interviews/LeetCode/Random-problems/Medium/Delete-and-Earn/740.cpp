int dp(int index, vector<int> &v, vector<int> &cache) {
    if (index > 10000) {
        return 0;
    }
    int &ans = cache[index];
    if (ans != -1) {
        return ans;
    }

    ans = max(dp(index + 1, v, cache), dp(index + 2, v, cache) + v[index]);
    return ans;
}

int deleteAndEarn(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans1 = 0, ans2 = 0;
    vector<int> v(10002, 0), cache(10002, -1);
    for (int i = 0; i < n; i++) {
        v[nums[i]] += nums[i];
    }

    return dp(1, v, cache);
}
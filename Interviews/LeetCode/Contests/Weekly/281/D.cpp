long long countPairs(vector<int> &nums, int k) {
    vector <pair<long long, long long>> v;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            v.push_back({i, 0ll});
            if (k / i != i) {
                v.push_back({k / i, 0ll});
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        long long curGcd = __gcd(k, nums[i]);
        for (auto &i: v) {
            ans += ((i.first * curGcd) % k == 0 ? i.second : 0);
            i.second += curGcd == i.first;
        }
    }

    return ans;
}
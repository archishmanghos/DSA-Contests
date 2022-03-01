vector<int> countBits(int n) {
    vector<int> ans;
    for (int num = 0; num <= n; ++num) {
        int count = 0;
        for (int i = 0; i < 18; i++) {
            count += (num & (1 << i)) != 0;
        }
        ans.push_back(count);
    }
    return ans;
}
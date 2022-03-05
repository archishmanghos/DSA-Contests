int mostFrequent(vector<int> &nums, int key) {
    vector<int> cnt(1005, 0);
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == key) {
            cnt[nums[i + 1]] += 1;
        }
    }
    int maxx = 0, maxAns = -1;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] > maxx) {
            maxx = cnt[i];
            maxAns = i;
        }
    }

    return maxAns;
}
int mostFrequentEven(vector<int>& nums) {
    vector<int> cnt(100005, 0);
    for (int i = 0; i < nums.size(); i++) {
        cnt[nums[i]] += 1;
    }

    int maxx = 0, maxNum = -1;
    for (int i = 0; i <= 100000; i += 2) {
        if (cnt[i] > maxx) {
            maxx = cnt[i];
            maxNum = i;
        }
    }

    return maxNum;
}
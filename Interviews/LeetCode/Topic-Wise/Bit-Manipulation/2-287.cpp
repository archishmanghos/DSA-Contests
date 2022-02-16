int findDuplicate(vector<int> &nums) {
    vector<int> bitCountShouldBe(18, 0), bitCount(18, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int k = 0; k < 18; k++) {
            if ((i & (1 << k)) != 0) {
                bitCountShouldBe[k] += 1;
            }
            if ((nums[i] & (1 << k)) != 0) {
                bitCount[k] += 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 18; i++) {
        if (bitCount[i] > bitCountShouldBe[i]) {
            ans += (1 << i);
        }
    }

    return ans;
}
int numberOfArithmeticSlices(vector<int> &nums) {
    if (nums.size() < 3) {
        return 0;
    }

    int countNow = 0, curDiff = nums[1] - nums[0], ans = 0;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] == curDiff) {
            countNow += 1;
        } else {
            curDiff = nums[i] - nums[i - 1];
            countNow = 0;
        }
        ans += countNow;
    }

    return ans;
}
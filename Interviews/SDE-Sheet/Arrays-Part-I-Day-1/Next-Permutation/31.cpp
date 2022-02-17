void nextPermutation(vector<int> &nums) {
    int breakpoint1 = -1, breakpoint2, n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            breakpoint1 = i;
            break;
        }
    }
    if (breakpoint1 != -1) {
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[breakpoint1]) {
                breakpoint2 = i;
                break;
            }
        }

        swap(nums[breakpoint1], nums[breakpoint2]);
    }

    reverse(nums.begin() + breakpoint1 + 1, nums.end());
}
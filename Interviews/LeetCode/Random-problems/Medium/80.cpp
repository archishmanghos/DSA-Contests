int removeDuplicates(vector<int> &nums) {
    int ans = 0;
    for (int i: nums) {
        if (ans < 2 or i > nums[ans - 2]) {
            nums[ans++] = i;
        }
    }
    return ans;
}
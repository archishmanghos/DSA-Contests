class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n / 2], ans = 0;

        for (int i : nums)
            ans += abs(med - i);

        return ans;
    }
};
class Solution {
public:
    bool check(int a, int b, int c) {
        return (a + b > c and a + c > b and b + c > a);
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 1; i--) {
            if (check(nums[i], nums[i - 1], nums[i - 2])) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }

        return 0;
    }
};
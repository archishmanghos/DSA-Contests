class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = -1, diff = 1e9, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x == target) {
                    return x;
                }
                if (abs(x - target) < diff) {
                    diff = abs(x - target);
                    ans = x;
                }

                if (x < target) {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }

        return ans;
    }
};
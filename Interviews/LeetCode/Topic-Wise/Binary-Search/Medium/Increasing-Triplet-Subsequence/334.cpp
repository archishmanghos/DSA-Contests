class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.size() == 0 or nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int lb = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[lb] = nums[i];
            }

            if (ans.size() > 2) return true;
        }

        return false;
    }
};
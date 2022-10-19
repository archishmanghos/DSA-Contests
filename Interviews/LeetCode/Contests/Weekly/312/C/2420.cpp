class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = suffix[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = 1;
            }
        }

        vector<int> ans;
        for (int i = 1; i < n - 1; i++) {
            if (prefix[i - 1] >= k and suffix[i + 1] >= k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
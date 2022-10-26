class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int sum = 0, n = nums.size();
        ump[0] = -1;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            if (ump.find(sum) != ump.end()) {
                if (i - ump[sum] > 1) return true;
            } else {
                ump[sum] = i;
            }
        }

        return false;
    }
};
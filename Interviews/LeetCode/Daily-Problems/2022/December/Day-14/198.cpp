#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp (int idx, int preRobbed, vector<int> &nums, vector<vector<int>> &cache) {
        if (idx == 0) {
            if (preRobbed) {
                return 0;
            }
            return nums[idx];
        }

        int &ans = cache[idx][preRobbed];
        if (ans != -1) {
            return ans;
        }

        ans = dp (idx - 1, 0, nums, cache);
        if (!preRobbed) {
            ans = max (ans, dp (idx - 1, 1, nums, cache) + nums[idx]);
        }

        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache (n, vector<int> (2, -1));
        return dp (n - 1, 0, nums, cache);
    }
};
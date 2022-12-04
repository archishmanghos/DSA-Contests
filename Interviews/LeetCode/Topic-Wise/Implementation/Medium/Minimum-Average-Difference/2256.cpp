#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumAverageDifference(vector<int>& nums) {
        int64_t leftSum = 0, rightSum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            rightSum += nums[i];
        }

        int i = -1;
        vector<int> ans = {(int)1e9, -1};
        while (++i < n) {
            leftSum += nums[i];
            rightSum -= nums[i];
            int avg = leftSum / (i + 1);
            if (i < n - 1) {
                avg = abs(avg - rightSum / (n - i - 1));
            }
            if (avg < ans[0]) {
                ans = {avg, i};
            }
        }

        return ans[1];
    }
};
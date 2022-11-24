#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> lis(vector<int>& a, int n) {
        vector<int> ans;
        vector<int> lisLen(n);
        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 or a[i] > ans.back()) {
                ans.push_back(a[i]);
            } else {
                int lb = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[lb] = a[i];
            }
            lisLen[i] = ans.size();
        }

        return lisLen;
    }

    int LongestBitonicSequence(vector<int> nums) {
        int n = nums.size();
        vector<int> forward = lis(nums, n);
        reverse(nums.begin(), nums.end());
        vector<int> backward = lis(nums, n);
        reverse(backward.begin(), backward.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, forward[i] + backward[i] - 1);
        }

        return ans;
    }
};
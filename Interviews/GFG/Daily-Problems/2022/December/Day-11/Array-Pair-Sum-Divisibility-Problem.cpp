#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if (n % 2) {
            return false;
        }

        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++) {
            cnt[nums[i] % k] += 1;
        }

        for (int i = 1; i <= k / 2; i++) {
            int cur = i, comp = k - i;
            if (cur == comp) {
                if (cnt[cur] % 2) {
                    return false;
                }
            } else {
                if (cnt[cur] != cnt[comp]) {
                    return false;
                }
            }
        }

        return true;
    }
};
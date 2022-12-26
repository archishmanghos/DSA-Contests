#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = nums[0];
        if (steps == 0) return nums.size() == 1;
        for (int i = 1; i < nums.size() - 1; i++) {
            steps = max (steps - 1, nums[i]);
            if (steps == 0) return 0;
        }

        return 1;
    }
};
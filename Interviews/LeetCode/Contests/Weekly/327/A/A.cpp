#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        for (int i : nums) {
            if (i < 0) neg += 1;
            if (i > 0) pos += 1;
        }

        return max (neg, pos);
    }
};
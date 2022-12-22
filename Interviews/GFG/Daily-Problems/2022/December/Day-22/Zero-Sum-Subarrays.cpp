#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<int, int64_t> mp;
        mp[0] += 1;
        int64_t sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            ans += mp[sum];
            mp[sum] += 1;
        }

        return ans;
    }
};
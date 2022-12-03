#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPossible(int dist, int k, vector<int>& stalls) {
        int lIdx = 0, cows = 1;
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - stalls[lIdx] >= dist) {
                lIdx = i;
                cows += 1;
                if (cows == k) {
                    return true;
                }
            }
        }

        return false;
    }

    int solve(int n, int k, vector<int>& stalls) {
        int low = 0, high = 1e9, ans = 0;
        sort(stalls.begin(), stalls.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, k, stalls)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
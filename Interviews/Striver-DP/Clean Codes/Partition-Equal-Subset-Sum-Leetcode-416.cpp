#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2) return false;
    vector<bool> preCache(sum + 1, 0);
    sum >>= 1;

    for (int i = n - 1; i >= 0; i--) {
        vector<bool> curCache(sum + 1, 0);
        for (int j = 0; j <= sum; j++) {
            if (i == n - 1) curCache[j] = (j == nums[i]);
            else {
                if (j == 0) curCache[j] = 1;
                else {
                    curCache[j] = preCache[j];
                    if (nums[i] <= j) {
                        curCache[j] = curCache[j] or preCache[j - nums[i]];
                    }
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[sum];
    return 0;
}
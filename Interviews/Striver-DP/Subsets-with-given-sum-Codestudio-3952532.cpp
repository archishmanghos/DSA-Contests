#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> preCache(k + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(k + 1, 0);
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                curCache[j] = 1;
                continue;
            }
            if (i == n - 1) {
                curCache[j] = (j == nums[i]);
                continue;
            }

            curCache[j] = preCache[j];
            if (nums[i] <= j) curCache[j] += preCache[j - nums[i]];
        }
        preCache = curCache;
    }

    cout << preCache[k];
    return 0;
}
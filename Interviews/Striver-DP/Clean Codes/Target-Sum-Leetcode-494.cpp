#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, target, totSum = 0; cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totSum += nums[i];
    }

    // Add or subtract and check if reach target
    // Let's assume 5 elements, a1, a2, a3, a4, a5
    // - a1 + a2 + a3 - a4 + a5 = target, or we can also write,
    // (a2 + a3 + a5) - (a1 + a4) = target
    // If, we represent (a1 + a4) as S1, we have
    // (totalSum - S1) - S1 = target, or
    // totalSum - target = 2S1, or
    // S1 = (totalSum - target) / 2, which means
    // We have to find a subset sum with target = (totalSum - target) / 2, which boils down to
    // Count subset sum with given target!

    if (totSum - target < 0 or (totSum - target) % 2) {
        cout << -1;
        return 0;
    }

    totSum = (totSum - target) / 2;
    vector<int> cache(totSum + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = totSum; j >= 0; j--) {
            if (i == n - 1) {
                if (j == 0 and nums[i] == 0) cache[j] = 2;
                else cache[j] = (j == 0 or j == nums[i]);
            } else {
                if (nums[i] <= j) cache[j] += cache[j - nums[i]];
            }
        }
    }

    cout << cache[totSum];
    return 0;
}
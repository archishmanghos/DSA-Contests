#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, totSum = 0; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totSum += nums[i];
    }

    vector<int> preCache(totSum + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(totSum + 1, 0);
        for (int j = totSum; j >= 0; j--) {
            if (i == n - 1) {
                int sumAfterNotPick = j, sumAfterPick = j - arr[i];
                int remSumAfterNotPick = totSum - sumAfterNotPick , remSumAfterPick = totSum - sumAfterPick;
                if (j == totSum) {
                    curCache[j] = abs(sumAfterPick - remSumAfterPick);
                } else if (j - arr[i] > 0) {
                    curCache[j] = min(abs(sumAfterPick - remSumAfterPick), abs(sumAfterNotPick - remSumAfterNotPick));
                } else {
                    curCache[j] = abs(sumAfterNotPick - remSumAfterNotPick);
                }
            } else {
                curCache[j] = preCache[j];
                if (j - arr[i] > 0) {
                    curCache[j] = min(curCache[j], preCache[j - arr[i]]);
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[totSum];
    return 0;
}
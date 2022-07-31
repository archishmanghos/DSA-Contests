#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, d, totSum = 0, mod = 1e9 + 7; cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totSum += arr[i];
    }

    vector<int> preCache(totSum + 1, 0), curCache(totSum + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = totSum; j >= 0; j--) {
            if (i == n - 1) {
                if (totSum - 2 * j == d) curCache[j] = 1;
                if (j + arr[i] <= totSum and totSum - 2 * (j + arr[i]) == d) {
                    curCache[j] = (curCache[j] + 1) % mod;
                }
            } else {
                curCache[j] = preCache[j];
                if (j + arr[i] <= totSum) curCache[j] = (curCache[j] + (preCache[j + arr[i]]) % mod) % mod;
            }
        }
        preCache = curCache;
    }

    cout << preCache[0];
    return 0;
}
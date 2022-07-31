#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, target; cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<bool> preCache(target + 1, false);

    for (int i = n - 1; i >= 0; i--) {
        vector<bool> curCache(target + 1, false);
        for (int j = target; j >= 0; j--) {
            if (i == n - 1) curCache[j] = (j == arr[i]);
            else {
                if (j == 0) curCache[j] = true;
                else {
                    curCache[j] = preCache[j];
                    if (arr[i] <= j) {
                        curCache[j] = curCache[j] or preCache[j - arr[i]];
                    }
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[target];
    return 0;
}
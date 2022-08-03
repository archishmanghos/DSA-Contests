#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<int> preToPreCache(2, 0);
    vector<int> preCache(2, 0);
    vector<int> curCache(2, 0);

    for (int i = n; i >= 0; i--) {
        if (i == n) curCache[0] = curCache[1] = 0;
        else if (i == n - 1) {
            curCache[1] = 0;
            curCache[0] = prices[i];
        } else {
            curCache[1] = max(preCache[0] - prices[i], preCache[1]);
            curCache[0] = max(preToPreCache[1] + prices[i], preCache[0]);
        }
        preToPreCache = preCache;
        preCache = curCache;
    }

    cout << curCache[1];
    return 0;
}
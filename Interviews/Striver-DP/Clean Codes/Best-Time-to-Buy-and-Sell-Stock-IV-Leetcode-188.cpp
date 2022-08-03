#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, k; cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<int> curCache(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 2 * k; j >= 0; j--) {
            if (j == 2 * k) curCache[j] = 0;
            else if (i == n - 1) {
                curCache[j] = (j % 2 == 0 ? 0 : prices[i]);
            } else {
                if (j % 2 == 0) {
                    curCache[j] = max(curCache[j + 1] - prices[i], curCache[j]);
                } else {
                    curCache[j] = max(curCache[j + 1] + prices[i], curCache[j]);
                }
            }
        }
    }

    cout << curCache[0];
    return 0;
}
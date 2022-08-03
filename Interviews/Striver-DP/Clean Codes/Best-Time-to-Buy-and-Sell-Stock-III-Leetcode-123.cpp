#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> curCache(2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k >= 0; k--) {
                if (i == n - 1) {
                    curCache[j][k] = (j ? 0 : prices[i]);
                } else {
                    if (j) {
                        curCache[j][k] = max(curCache[0][k] - prices[i], curCache[1][k]);
                    } else {
                        curCache[j][k] = curCache[0][k];
                        if (k + 1 < 2) {
                            curCache[j][k] = max(curCache[j][k], curCache[1][k + 1] + prices[i]);
                        } else {
                            curCache[j][k] = max(curCache[j][k], prices[i]);
                        }
                    }
                }
            }
        }
    }

    cout << curCache[1][0];
    return 0;
}
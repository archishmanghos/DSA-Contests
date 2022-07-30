#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, amount; cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> preCache(amount + 1, 0), curCache(amount + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= amount; j++) {
            if (j == 0) curCache[j] = 1;
            else if (i == n - 1) curCache[j] = (j % coins[i] == 0);
            else {
                curCache[j] = preCache[j];
                if (coins[i] <= j) curCache[j] += curCache[j - coins[i]];
            }
        }
        preCache = curCache;
    }

    cout << preCache[amount];
    return 0;
}
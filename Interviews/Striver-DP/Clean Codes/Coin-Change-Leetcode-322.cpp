#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> cache(x + 1, 10001000);
    for (int i = 0; i <= x; i++) {
        if (i == 0) cache[i] = 0;
        else {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    cache[i] = min(cache[i], cache[i - coins[j]] + 1);
                }
            }
        }
    }

    if (cache[x] == 10001000) cout << -1;
    else cout << cache[x];
    return 0;
}
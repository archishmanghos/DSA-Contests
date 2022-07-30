#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++) cin >> profit[i];
    for (int i = 0; i < n; i++) cin >> weight[i];

    vector<int> cache(w + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= w; j++) {
            if (i == n - 1) cache[j] = (j / weight[i]) * profit[i];
            else {
                if (weight[i] <= j) {
                    cache[j] = max(cache[j], cache[j - weight[i]] + profit[i]);
                }
            }
        }
    }

    cout << cache[w];
    return 0;
}
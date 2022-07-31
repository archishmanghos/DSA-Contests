#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    vector<int> cache(w + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = w; j >= 0; j--) {
            if (i == n - 1) {
                cache[j] = (weight[i] <= j ? value[i] : 0);
            } else {
                if (weight[i] <= j) {
                    cache[j] = max(cache[j], cache[j - weight[i]] + value[i]);
                }
            }
        }
    }

    cout << cache[w];
    return 0;
}
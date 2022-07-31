#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> m >> n;
    vector<int> preCache(n + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        vector<int> curCache(n + 1, 0);
        curCache[n - 1] = 1;
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 and j == n - 1) continue;
            curCache[j] = curCache[j + 1] + preCache[j];
        }
        preCache = curCache;
    }

    cout << preCache[0];
    return 0;
}
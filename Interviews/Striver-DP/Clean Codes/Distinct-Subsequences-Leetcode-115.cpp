#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size(), mod = 1e9 + 7;

    vector<int> curCache(m + 1, 0);
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            if (i == n or j == m) {
                curCache[j] = j == m;
            } else {
                if (s[i] == t[j]) {
                    curCache[j] = (curCache[j + 1] % mod + curCache[j] % mod) % mod;
                }
            }
        }
    }

    cout << curCache[0];
    return 0;
}
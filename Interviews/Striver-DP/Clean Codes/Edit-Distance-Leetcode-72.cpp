#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> preCache(m + 1, 0), curCache(m + 1, 0);
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n or j == m) {
                if (i == n) curCache[j] = m - j;
                else curCache[j] = n - i;
            } else {
                if (s[i] == t[j]) {
                    curCache[j] = preCache[j + 1];
                } else {
                    curCache[j] = 1 + min(preCache[j + 1], min(preCache[j], curCache[j + 1]));
                }
            }
        }
        preCache = curCache;
    }

    cout << curCache[0];
    return 0;
}
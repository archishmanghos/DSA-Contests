#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> preCache(m + 1, 0), curCache(m + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                curCache[j] = 1 + preCache[j + 1];
            } else {
                curCache[j] = max(preCache[j], curCache[j + 1]);
            }
        }
        preCache = curCache;
    }

    cout << preCache[0];
    return 0;
}
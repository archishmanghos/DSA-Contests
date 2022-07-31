#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s; cin >> s;
    int n = s.size();

    vector<int> preCache(n + 1, 0), curCache(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == s[j - 1]) {
                curCache[j] = 1 + preCache[j - 1];
            } else {
                curCache[j] = max(preCache[j], curCache[j - 1]);
            }
        }
        preCache = curCache;
    }

    cout << preCache[n];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s; cin >> s;
    int n = s.size();

    vector<int> preCache(n + 1, 0), curCache(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i >= j) curCache[j] = 0;
            else {
                if (s[i] == s[j]) {
                    curCache[j] = preCache[j - 1];
                } else {
                    curCache[j] = min(preCache[j] + 1, curCache[j - 1] + 1);
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[n - 1];
    return 0;
}
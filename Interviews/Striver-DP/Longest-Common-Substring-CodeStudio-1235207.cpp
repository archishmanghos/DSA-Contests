#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string str1, str2; cin >> str1 >> str2;
    int n = str1.size(), m = str2.size(), ans = 0;
    vector<int> preCache(m + 1, 0), curCache(m + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                curCache[j] = 1 + preCache[j + 1];
                ans = max(ans, curCache[j]);
            } else {
                curCache[j] = 0;
            }
        }
        preCache = curCache;
    }

    cout << ans;
    return 0;
}
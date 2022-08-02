#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                cache[i][j] = 1 + cache[i + 1][j + 1];
            } else {
                cache[i][j] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }

    string ans((m + n) - cache[0][0], '0');
    int i = 0, j = 0, index = 0;

    while (i < n and j < m) {
        if (s[i] == t[j]) {
            ans[index++] = s[i];
            i++, j++;
        } else {
            if (i + 1 < n and j + 1 < m) {
                if (cache[i + 1][j] < cache[i][j + 1]) {
                    ans[index++] = t[j++];
                } else {
                    ans[index++] = s[i++];
                }
            } else {
                if (i + 1 < n) {
                    ans[index++] = s[i++];
                } else {
                    ans[index++] = t[j++];
                }
            }
        }
    }

    while (i < n) ans[index++] = s[i++];
    while (j < m) ans[index++] = t[j++];

    cout << ans;
    return 0;
}
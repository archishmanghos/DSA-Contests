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

    string ans(cache[0][0], 'a');
    int row = 0, col = 0, i = 0;

    while (i < cache[0][0]) {
        if (s[row] == t[col]) {
            ans[i++] = s[row];
            row++, col++;
        } else {
            if (row + 1 == n) {
                col++;
            } else if (col + 1 == m) {
                row++;
            } else {
                if (cache[row + 1][col] > cache[row][col + 1]) row++;
                else col++;
            }
        }
    }

    cout << ans;
    return 0;
}
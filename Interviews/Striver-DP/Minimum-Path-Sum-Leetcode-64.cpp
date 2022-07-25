#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> preCache(m + 1, 200200);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(m + 1, 200200);
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 and j == m - 1) curCache[j] = grid[i][j];
            else curCache[j] = min(preCache[j], curCache[j + 1]) + grid[i][j];
        }
        preCache = curCache;
    }

    cout << preCache[0];
    return 0;
}
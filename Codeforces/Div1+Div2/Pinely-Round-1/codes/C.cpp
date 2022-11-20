#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<set<int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].insert(i + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                for (int k : ans[i]) {
                    ans[j].insert(k);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i].size() << ' ';
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

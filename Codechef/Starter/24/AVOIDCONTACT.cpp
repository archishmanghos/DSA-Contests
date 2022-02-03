#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int X, Y;
    cin >> X >> Y;
    int ans = 2 * Y;
    if (X - Y == 0) {
        cout << ans - 1 << '\n';
    } else {
        cout << ans + (X - Y) << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
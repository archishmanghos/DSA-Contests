#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    string S;
    cin >> S;
    int cnt[2] = {0};
    for (char c: S) {
        cnt[c - '0'] += 1;
    }
    if (cnt[0] == cnt[1]) {
        cout << cnt[0] - 1 << '\n';
    } else {
        cout << min(cnt[0], cnt[1]) << '\n';
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
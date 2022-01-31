#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    string S;
    cin >> N >> S;

    if (S.size() == 1) {
        cout << "YES" << '\n';
    } else if (S.size() == 2) {
        cout << (S[0] == S[1] ? "NO" : "YES") << '\n';
    } else {
        cout << "NO" << '\n';
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
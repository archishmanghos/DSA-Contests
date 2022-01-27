#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0, i = N, jump = 0;
    while (i >= 1) {
        if (A[i] == A[N]) {
            jump += 1;
            i -= 1;
        } else {
            ans += 1;
            i -= jump;
            jump <<= 1;
        }
    }

    cout << ans << '\n';
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
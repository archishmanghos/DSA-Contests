#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 2);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int xorr = K;
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) != 0) {
                xorr ^= A[j];
            }
        }
        ans = max(ans, xorr);
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
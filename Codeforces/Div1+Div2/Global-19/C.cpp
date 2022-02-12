#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N + 2);
    int odd = 0, oddGreaterThan1 = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        odd += (i > 1 and i < N and (A[i] % 2 == 1));
        oddGreaterThan1 += (i > 1 and i < N and (A[i] % 2 == 1) and A[i] > 1 and N > 3);
    }

    int ans = 0;
    for (int i = 2; i <= N - 1; i++) {
        ans += (A[i] + 1) / 2;
    }
    if (odd < N - 2) {
        cout << ans << '\n';
    } else {
        if (oddGreaterThan1 > 0) {
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
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
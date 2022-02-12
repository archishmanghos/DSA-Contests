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

    vector<int> suffixMin(N + 2);
    int minn = INF;
    for (int i = N; i >= 1; i--) {
        suffixMin[i] = min(minn, A[i]);
        minn = min(minn, A[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] > suffixMin[i]) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
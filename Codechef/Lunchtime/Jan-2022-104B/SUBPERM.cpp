#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, K;
    cin >> N >> K;

    if (N > 1 and K < 2) {
        cout << -1 << '\n';
        return;
    }

    vector<int> A(N + 2);
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    swap(A[K], A[N]);

    for (int i = 1; i <= N; i++) {
        cout << A[i] << ' ';
    }
    cout << '\n';
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
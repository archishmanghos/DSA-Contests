#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, X, Y, B;
    cin >> N >> X >> Y;
    vector<int> A(N + 2);
    set<int> diff;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B;
        diff.insert(B - A[i]);
    }

    if (diff.size() <= 2) {
        if (diff.size() == 1) {
            cout << ((*diff.begin() == X or *diff.begin() == Y) ? "YES" : "NO") << '\n';
        } else {
            cout << ((*diff.begin() == min(X, Y) and *diff.rbegin() == max(X, Y)) ? "YES" : "NO") << '\n';
        }
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
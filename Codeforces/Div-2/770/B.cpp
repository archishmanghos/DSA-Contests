#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, X, Y, A;
    cin >> N >> X >> Y;
    bool parityX = X % 2 != 0; // true if odd, false if even
    bool parityY = Y % 2 != 0;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        if (A % 2) {
            parityX = !parityX;
        }
    }

    cout << (parityX == parityY ? "Alice" : "Bob") << '\n';
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
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << "YES" << '\n';
        for (int i = 1; i <= N; i++) {
            cout << i << '\n';
        }
    } else if (N > 1 and (((N & (N - 1)) == 0) and K == 2)) {
        cout << "YES" << '\n';
        int k = 1, l = ((N * K) / 2) + 1;
        for (int i = 1; i <= N; i++) {
            cout << k++ << ' ' << l++ << '\n';
        }
    } else {
        int total = N * K;
        int odd = (total % 2 ? total / 2 : (total + 1) / 2);
        if (odd % K == 0 and ((total - odd) % K == 0)) {
            cout << "YES" << '\n';
            int alternate = 0, k = 1, l = 2;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= K; j++) {
                    if (alternate) {
                        cout << k << ' ';
                        k += 2;
                    } else {
                        cout << l << ' ';
                        l += 2;
                    }
                }
                cout << '\n';
                alternate ^= 1;
            }
        } else {
            cout << "NO" << '\n';
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
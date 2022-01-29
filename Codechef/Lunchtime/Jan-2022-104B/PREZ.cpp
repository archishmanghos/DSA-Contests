#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int ans = 0, pre = -1, operations;
    for (int i = 0; i < N; i++) {
        if (pre == -1) {
            operations = (10 - (S[i] - '0')) % 10;
        } else {
            if (((10 - (S[i] - '0')) % 10) > pre) {
                operations += 10;
            }
        }

        pre = ((10 - (S[i] - '0')) % 10);
        if (K >= operations) {
            ans += 1;
        } else {
            break;
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
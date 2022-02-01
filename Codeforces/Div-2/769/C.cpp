#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e6 + 5;
const int INF = 1e18 + 7;

void solve() {
    int A, B;
    cin >> A >> B;
    int ans = B - A, maxStep = B - A, cnt = 0, B1 = B;

    while (cnt <= maxStep) {
        int temp = A | B;
        ans = min(ans, 1 + cnt + temp - B);
        B += 1;
        cnt += 1;
    }

    B = B1, cnt = 0;
    while (A <= B) {
        int temp = A | B;
        ans = min(ans, 1 + cnt + temp - B);
        A += 1;
        cnt += 1;
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
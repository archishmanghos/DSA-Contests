#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int nextHighestPower2(int N) {
    int x = 1;
    while (x <= N) {
        x <<= 1;
    }
    return x - 1;
}

void solve() {
    int N, ans = 0;
    cin >> N;

    while (N > 0) {
        int power2 = nextHighestPower2(N);
        if (N == power2) {
            N -= 1;
        }
        int diff = power2 - N;
        int placesCovered = N - diff + 1;
        ans += placesCovered * power2;
        N = diff - 1;
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
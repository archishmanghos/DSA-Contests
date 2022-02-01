#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, K;
vector<int> minPaths(2005), B(1005), C(1005);

int dp(int index, int coinsLeft, vector<vector<int>> &cache) {
    if (index > N) {
        return 0;
    }

    if (cache[index][coinsLeft] != -1) {
        return cache[index][coinsLeft];
    }

    int ans = 0;
    if (minPaths[B[index]] <= coinsLeft) {
        ans = max(dp(index + 1, coinsLeft - minPaths[B[index]], cache) + C[index], dp(index + 1, coinsLeft, cache));
    } else {
        ans = dp(index + 1, coinsLeft, cache);
    }

    return cache[index][coinsLeft] = ans;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }

    int maxCoinsRequired = 0;
    for (int i = 1; i <= N; i++) {
        maxCoinsRequired += minPaths[B[i]];
    }

    if (maxCoinsRequired <= K) {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += C[i];
        }
        cout << ans << '\n';
        return;
    }

    vector<vector<int>> cache(1005, vector<int>(K + 2, -1));
    cout << dp(1, K, cache) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    minPaths.assign(2005, INF);
    minPaths[1] = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            minPaths[i + i / j] = min(minPaths[i + i / j], minPaths[i] + 1);
        }
    }

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
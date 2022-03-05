#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/Clion/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e6 + 5;
const int INF = 1e18 + 7;
const int mod = 998244353;

int dp(int index, int preDigit, vector<vector<int>> &cache, int &n) {
    if (index > n) {
        return 1;
    }

    if (cache[index][preDigit] != -1) {
        return cache[index][preDigit];
    }

    int ans = 0;
    if (index == 1) {
        for (int i = 1; i <= 9; i++) {
            ans = (ans + dp(index + 1, i, cache, n) % mod) % mod;
        }
    } else {
        int from = max((int) 1, preDigit - 1), upto = min((int) 9, preDigit + 1);
        for (int i = from; i <= upto; i++) {
            ans = (ans + dp(index + 1, i, cache, n) % mod) % mod;
        }
    }
    return cache[index][preDigit] = ans % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vector<vector<int>> cache(N + 5, vector<int>(10, -1));
    cout << dp(1, 0, cache, N);

    return 0;
}
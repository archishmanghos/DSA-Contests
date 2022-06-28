#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
string S;

void solve() {

    cin >> S;
    vector<int> cnt(26, 0);
    for (char c : S) {
        cnt[c - 'a'] += 1;
    }

    int ans = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= cnt[i]; j++)
            ans *= j;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
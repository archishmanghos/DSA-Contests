#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    set<string> countryCodes;
    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        string temp = "";
        temp += S[i];
        temp += S[i + 1];
        ans += (countryCodes.find(temp) == countryCodes.end());
        countryCodes.insert(temp);
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
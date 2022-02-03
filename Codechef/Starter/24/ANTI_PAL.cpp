#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N & 1) {
        cout << "NO" << '\n';
        return;
    }

    sort(S.begin(), S.end());
    string s1 = S.substr(0, N / 2);
    string s2 = S.substr(N / 2);
    reverse(s2.begin(), s2.end());
    string final = s1 + s2;

    int i = 0, j = N - 1;
    while (i < j) {
        if (final[i] == final[j]) {
            cout << "NO" << '\n';
            return;
        }
        i += 1, j -= 1;
    }

    cout << "YES" << '\n' << final << '\n';
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
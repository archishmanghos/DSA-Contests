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

int T, N, B[mxN];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    string s = "E";
    for (int i = 1; i < N; i++) {
        if (s.back() == 'E') {
            if (B[i] == 0)
                s += 'E';
            else
                s += 'O';
        } else {
            if (B[i] == 0)
                s += 'O';
            else
                s += 'E';
        }
    }

    if ((s[0] == s.back() and B[N] == 0) or (s[0] != s.back() and B[N] == 1)) {
        cout << "YES" << '\n';
        return;
    }

    s = "O";
    for (int i = 1; i < N; i++) {
        if (s.back() == 'E') {
            if (B[i] == 0)
                s += 'E';
            else
                s += 'O';
        } else {
            if (B[i] == 0)
                s += 'O';
            else
                s += 'E';
        }
    }

    if ((s[0] == s.back() and B[N] == 0) or (s[0] != s.back() and B[N] == 1)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
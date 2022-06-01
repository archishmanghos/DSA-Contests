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

int T, X, Y;

void solve() {
	cin >> X >> Y;
	if(X <= Y) cout << (Y - X) << '\n';
	else {
		if((X - Y) & 1) cout << (X - Y + 1) / 2 + 1 << '\n';
		else cout << (X - Y) / 2 << '\n';
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}
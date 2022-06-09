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
	for(int i = 1; i <= N; i++) cin >> B[i];

	int minn = INF, maxx = 0, OK = 1;
	for(int i = 1; i <= N; i++){
		maxx = max(maxx, B[i]);
		minn = min(minn, B[i]);
		if(B[i] != maxx and B[i] != minn) OK = 0;
	}

	cout << (OK ? "YES" : "NO") << '\n';
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
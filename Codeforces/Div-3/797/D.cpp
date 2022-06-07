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

int T, N, K;
string S;

void solve() {
	cin >> N >> K >> S;
	int ans = INF, white = 0;
	for(int i = 0; i < K; i++) white += S[i] == 'W';
	ans = white;
	for(int i = 1; i <= N - K; i++) {
		white += S[i + K - 1] == 'W';
		white -= S[i - 1] == 'W';
		ans = min(ans, white);
	}

	cout << ans << '\n';
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
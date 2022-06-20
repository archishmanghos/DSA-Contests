// Subtask 1 solved


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

int T, N, A[mxN];

void solve() {
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	int ans = 0;
	for(int i = 1; i <= N; i++){
		int temp[N + 2];
		temp[1] = A[N];
		for(int j = 2; j <= N; j++) temp[j] = A[j - 1];

		set<int> distinct;
		int xorValue = 0;
		for(int j = 1; j <= N; j++) {
			xorValue ^= temp[j];
			distinct.insert(xorValue);
		}
		ans = max(ans, (int)distinct.size());
		for(int j = 1; j <= N; j++) A[j] = temp[j];
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
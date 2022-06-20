// subtask 1 solved


#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, A[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N;
	for(int i = 1; i <= N; i++)cin >> A[i];
	int ans = 0;
	for(int i = 1; i < N; i++){
		for(int j = i + 1; j <= N; j++) ans += 2 * (A[i] ^ A[j]) == A[i] + A[j];
	}

	cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN], M, B;

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
	int shuffles = 0;
	for(int i = 1; i <= M; i++) {
		cin >> B;
		shuffles += B;
	}

	cout << A[shuffles % N + 1] << '\n';
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
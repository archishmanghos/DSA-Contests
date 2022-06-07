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

int T, N, A[mxN], B[mxN];

void solve() {
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++) cin >> B[i];

	vector<int> C(N + 2);
	int maxDiff = 0;
	for(int i = 1; i <= N; i++) {
		C[i] = A[i] - B[i];
		if(C[i] < 0) {
			cout << "NO" << '\n';
			return;
		}
		maxDiff = max(maxDiff, C[i]);
	}

	for(int i = 1; i <= N; i++){
		if(C[i] != maxDiff){
			if(B[i] != 0) {
				cout << "NO" << '\n';
				return;
			}
		}
	}

	cout << "YES" << '\n';
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
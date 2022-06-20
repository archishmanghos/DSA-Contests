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
	for(int i = 1; i <= N + 1; i++) cin >> A[i];

	if(N & 1){
		int totXor = 0;
		for(int i = 1; i <= N + 1; i++) totXor ^= A[i];
		bool once = false;
		for(int i = 1; i <= N + 1; i++){
			if(totXor == A[i] and !once) {
				once = true;
				continue;
			}
			cout << (totXor ^ A[i]) << ' ';
		}
		cout << '\n';
	}else{
		sort(A + 1, A + N + 1 + 1);
		int totXor = A[1];
		for(int i = 2; i <= N + 1; i++){
			cout << (totXor ^ A[i]) << ' ';
		}
		cout << '\n';
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
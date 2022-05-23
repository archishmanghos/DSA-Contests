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

int T, N, A[mxN], B[mxN];

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
    	cin >> A[i];
    	B[i] = A[i];
    }

    sort(B + 1, B + N + 1);
    int ans = -1;
    for(int i = 1; i <= N; i++){
    	if(A[i] != B[i]){
    		if(ans == -1) ans = (A[i] & B[i]);
    		else ans &= (A[i] & B[i]);
    	}
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
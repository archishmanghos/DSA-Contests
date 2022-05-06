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

int T, N, A[35];

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    int ans = 0;
    for(int i = N - 1; i >= 1; i--){
    	while(A[i] >= A[i + 1]){
    		if(A[i] == 0){
    			break;
    		}
    		A[i] >>= 1;
    		ans += 1;
    	}
    }

    for(int i = 1; i < N; i++){
    	if(A[i] >= A[i + 1]){
    		cout << -1 << '\n';
    		return;
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
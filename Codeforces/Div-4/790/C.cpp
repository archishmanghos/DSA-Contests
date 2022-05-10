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

int T, N, M;
string S[55];

void solve() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
    	cin >> S[i];
    }

    int ans = INF;
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++){
    		if(i != j){
    			int diff = 0;
    			for(int k = 0; k < M; k++){
    				diff += abs(S[i][k] - S[j][k]);
    			}
    			ans = min(ans, diff);
    		}
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
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

int T, N, Q, A[mxN], X;

void solve() {
    cin >> N >> Q;
    vector<int> prefSum(N, 0);
    int sum = 0;

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    sort(A + 1, A + N + 1, greater<int>());
    for(int i = 1; i <= N; i++){
    	sum += A[i];
    	prefSum[i - 1] = sum;
    }

    while(Q--){
    	cin >> X;
    	if(X > prefSum[N - 1]){
    		cout << -1 << '\n';
    	}else{
    		int lb = lower_bound(prefSum.begin(), prefSum.end(), X) - prefSum.begin();
    		cout << lb + 1 << '\n';
    	}
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
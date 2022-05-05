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

int T, N, A[mxN];

void solve() {
    cin >> N;
    int minn = INF;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	minn = min(minn, A[i]);
    }

    int start = 1;
    if(N & 1){
    	if(A[1] != minn){
    		cout << "NO" << '\n';
    		return;
    	}
    	start += 1;
    }

    for(int i = start; i < N; i += 2){
    	if(A[i] > A[i + 1]){
    		swap(A[i], A[i + 1]);
    	}
    }

    if(N > 1){
    	int pre = -1;
	    for(int i = start; i <= N; i++){
	    	if(A[i] < pre){
	    		cout << "NO" << '\n';
	    		return;
	    	}
	    	pre = A[i];
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
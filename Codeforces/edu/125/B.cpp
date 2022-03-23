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

int T, N, B, X, Y;

void solve()
{
    cin >> N >> B >> X >> Y;
    vector<int> A(N + 2, 0);

    for(int i = 1; i <= N; i++){
    	if(A[i - 1] + X <= B){
    		A[i] = A[i - 1] + X;
    	}else{
    		A[i] = A[i - 1] - Y;
    	}
    }

    int ans = 0;
    for(int i = 0; i <= N; i++){
    	ans += A[i];
    }

    cout << ans << '\n';
}

int32_t main()
{
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
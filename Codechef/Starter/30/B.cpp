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

int T, N, K, A[mxN];

void solve()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    sort(A + 1, A + N + 1);
    int ans = 0, sum = 0;
    for(int i = 0; i <= N; i++){
    	sum += A[i];
    	if(sum <= K){
    		ans = max(ans, i);
    	}
    	if(sum + (A[i + 1] + 1) / 2 <= K){
    		ans = max(ans, min(i + 1, N));
    	}
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
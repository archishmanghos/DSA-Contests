#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int MOD = 998244353;
const int INF = 1e18 + 7;

int T, N;

void solve()
{
    cin >> N;
    if(N & 1){
    	cout << 0 << '\n';
    }else{
    	int half = N / 2;
    	int ans = 1;
    	for(int i = 1; i <= half; i++){
    		ans = (ans *i) % MOD;
    	}
    	ans = ((ans % MOD) * (ans % MOD)) % MOD;
    	cout << ans << '\n';
    }
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
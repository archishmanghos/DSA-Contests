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

int T, N;

void solve()
{
    cin >> N;
    int ans = 0, i = 1, sum = 1;

    while(1){
    	ans += i - 1;
    	i <<= 1;
    	sum += i;
    	if(sum == N){
    		ans += (i - 1);
    		break;
    	}
    	if(sum > N){
    		sum -= i;
    		ans += (N - sum - 1);
    		break;
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
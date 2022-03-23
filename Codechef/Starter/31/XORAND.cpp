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

void solve()
{
    cin >> N;

    vector<int> cnt(32, 0);
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	for(int j = 31; j >= 0; j--){
    		if((A[i] & (1 << j)) != 0){
    			cnt[j] += 1;
    			break;
    		}
    	}
    }

    int ans = 0;
    for(int i = 0; i <= 31; i++){
    	ans += cnt[i] * (cnt[i] - 1) / 2;
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
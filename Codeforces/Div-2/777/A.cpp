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
    if(N == 1){
    	cout << 1 << '\n';
    }else{
    	if(N % 3 == 1) {
    		int cnt = 0;
    		while(N > 0){
    			cout << (cnt ? 2 : 1);
    			N -= (cnt ? 2 : 1);
    			cnt ^= 1;
    		}
    		cout << '\n';
    	}else{
    		int cnt = 0;
    		while(N > 0){
    			cout << (cnt ? 1 : 2);
    			N -= (cnt ? 1 : 2);
    			cnt ^= 1;
    		}
    		cout << '\n';
    	}
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
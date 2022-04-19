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

void solve()
{
    cin >> N >> M;
    if(N == M){
    	cout << (min(N, M) - 1) * 2 << '\n';
    }else if(N == 1 or M == 1){
    	if(max(N, M) > 2){
    		cout << -1 << '\n';
    	}else{
    		cout << 1 << '\n';
    	}
    }else{
		if(N > M){
			if((N - M) & 1){
				cout << ((min(N, M) - 1) * 2 + (N - M) * 2 - 1) << '\n';
			}else{
				cout << ((min(N, M) - 1) * 2 + (N - M) * 2) << '\n';
			}
		}else{
			if((N - M) & 1){
				cout << ((min(N, M) - 1) * 2 + (M - N) * 2 - 1) << '\n';
			}else{
				cout << ((min(N, M) - 1) * 2 + (M - N) * 2) << '\n';
			}
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
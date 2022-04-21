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
string S;

void solve()
{
    cin >> N >> S;
    int blue = 0, red = 0, ans = 0;
    for(int i = 0; i < N; i++){
    	if(S[i] == 'W'){
    		if((blue == 0 and red) or (blue and red == 0)){
    			cout << "NO" << '\n';
    			return;
    		}

    		blue = red = 0;
    	}
    	blue += S[i] == 'B';
    	red += S[i] == 'R';
    }

    if((blue == 0 and red) or (blue and red == 0)){
		cout << "NO" << '\n';
		return;
	}
    cout << "YES" << "\n";
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
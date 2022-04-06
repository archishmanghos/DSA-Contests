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
    bool ok = true;
    for(auto i : S){
    	ok &= i == '0';
    }

    if(ok){
    	cout << 0 << '\n';
    	return;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
    	if(S[i] == '1'){
    		cnt += 1;
    	}else{
    		if(cnt > 1){
    			cout << 2 << '\n';
    			return;
    		}
    		cnt = 0;
    	}
    }
    cout << (cnt > 1 ? 2 : 1) << '\n';
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
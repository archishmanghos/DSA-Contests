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

int T;
string S;

void solve()
{
    cin >> S;
    int N = S.size();

    int cnt = 1;
    for(int i = 1; i < N; i++){
    	if(S[i] == S[i - 1]){
    		cnt += 1;
    	}else{
    		if(cnt == 1){
    			cout << "NO" << '\n';
    			return;
    		}
    		cnt = 1;
    	}
    }

    cout << (cnt == 1 ? "NO" : "YES") << '\n';
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
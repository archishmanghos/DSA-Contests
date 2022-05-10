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

void solve() {
    cin >> S;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < S.size(); i++){
    	if(i <= 2){
    		sum1 += S[i] - '0';
    	}else{
    		sum2 += S[i] - '0';
    	}
    }

    cout << (sum1 == sum2 ? "YES" : "NO") << '\n';
}

int32_t main() {
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
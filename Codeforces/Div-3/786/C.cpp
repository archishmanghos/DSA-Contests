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
string A, B;

void solve() {
    cin >> A >> B;
    if(B == "a"){
    	cout << 1 << '\n';
    	return;
    }
    int N = A.size();
    for(char c : B){
    	if(c == 'a'){
    		cout << -1 << '\n';
    		return;
    	}
    }

    int ans = 1;
    for(int i = 1; i <= N; i++){
    	ans *= 2;
    }

    cout << ans << '\n';
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
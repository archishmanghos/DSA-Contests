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
    int N = S.size();

    int last1 = 0, first0 = N - 1;
    for(int i = 0; i < N; i++){
    	if(S[i] == '1'){
    		last1 = i;
    	}
    	if(S[i] == '0'){
    		first0 = min(i, first0);
    	}
    }

    if(first0 > last1){
		cout << (first0 - last1 + 1) << '\n';
	}else{
		cout << 1 << '\n';
	}
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
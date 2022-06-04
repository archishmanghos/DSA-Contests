#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, X;

void solve() {
	cin >> X;
	int Y = 0, cntSet = 0;
	for(int i = 0; i < 32; i++){
		if(X & (1 << i)){
			if(cntSet == 0) Y |= (1 << i);
			cntSet += 1;
		}
	}

	if(cntSet > 1) cout << Y << '\n';
	else{
		for(int i = 0; i < 32; i++){
			if((X & (1 << i)) == 0) {
				Y |= (1 << i);
				break;
			}
		}

		cout << Y << '\n';
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
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

int T, A, B, C, X, Y;

void solve() {
	cin >> A >> B >> C >> X >> Y;

	int req = 0;
	if(X > A){
		req = X - A;
	}

	int rem = (C - req);
	if(rem < 0){
		cout << "NO" << '\n';
		return;
	}

	if(B + rem >= Y){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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
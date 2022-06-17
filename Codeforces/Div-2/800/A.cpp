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

int T, one, zero;

void solve() {
	cin >> zero >> one;
	int distribution = max(zero, one) / min(zero, one);
	for(int i = 1; i <= min(zero, one); i++){
		if(zero < one) {
			cout << 0;
			for(int i = 1; i <= distribution; i++) cout << 1;
		}
		else {
			cout << 1;
			for(int i = 1; i <= distribution; i++) cout << 0;
		}
	}

	if(zero > one){
		for(int i = 1; i <= zero - one *distribution; i++) cout << 0;
	}else{
		for(int i = 1; i <= one - zero *distribution; i++) cout << 1;
	}

	cout << '\n';
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
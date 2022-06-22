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

int T, N, A;

void solve() {
    
    cin >> N;
    int prefSum = 0, ans = 1;
    bool shouldBeZero = false;

    for(int i = 1; i <= N; i++){
    	cin >> A;
    	if(shouldBeZero) {
    		if(A != 0) ans = 0;
    		continue;
    	}

    	prefSum += A;
    	if(prefSum == 0) shouldBeZero = true;
    	else if(prefSum < 0) ans = 0;
    }

    cout << (ans and !prefSum ? "Yes" : "No") << '\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
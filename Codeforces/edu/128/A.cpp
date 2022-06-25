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

int T, L1, L2, R1, R2;

void solve() {
    
	cin >> L1 >> R1 >> L2 >> R2;
	if(max(L1, L2) > min(R1, R2)) cout << L1 + L2 << '\n';
	else cout << max(L1, L2) << '\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
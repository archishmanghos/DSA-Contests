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

int T, N;

void solve() {
    
    cin >> N;

    if(N < 4 or (N & 1)) {
    	cout << -1 << '\n';
    	return;
    }

    int min6 = N / 6, min4 = 0;
    if(N % 6 == 2) min6 -= 1, min4 = 2;
    else if(N % 6 == 4) min4 = 1;
    
    int max4 = N / 4, max6 = 0;
    if(N % 4 == 2) max4 -= 1, max6 = 1;

    cout << (min4 + min6) << ' ' << (max4 + max6) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}
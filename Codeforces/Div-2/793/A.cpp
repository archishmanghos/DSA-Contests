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

int T, N;
string S;

void solve() {
    cin >> N >> S;
    int i, j;
    if(N & 1) i = N / 2, j = N / 2;
    else i = (N - 1) / 2, j = N / 2;

    int ans = (j - i + 1);
    while(i >= 0 and j < N){
    	i--, j++;
    	if(S[i] != S[N / 2]) break;
    	ans += 2;
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
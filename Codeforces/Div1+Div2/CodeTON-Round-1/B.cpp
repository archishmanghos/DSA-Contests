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

int T, N, K, A[mxN];

void solve()
{
    cin >> N >> K;
    set<int> s;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	s.insert(A[i]);
    }

    for(int i = 1; i <= N; i++){
    	if(s.find(A[i] + K) != s.end()){
    		cout << "YES" << '\n';
    		return;
    	}
    }

    cout << "NO" << '\n';
}

int32_t main()
{
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
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

int T, N, M, A[mxN];

void solve()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}

	sort(A + 1, A + N + 1);
	int ans = 1;
	for(int i = 2; i <= N; i++){
		ans += max(A[i], A[i - 1]) + 1;
	}
	ans += max(A[1], A[N]);

	if(ans <= M){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
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
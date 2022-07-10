#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int T, N, M, A[mxN];

void solve() {
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A + N + 1);
	
	double ans = 0.0;
	for(int i = N; i > (N - M + 1); i--){
		ans += A[i];
	}

	int rem = N - M + 1;
	if(rem % 2 == 0){
		double avg = (A[rem / 2] + A[(rem / 2) + 1]) / 2.0;
		ans += avg;
	}else{
		ans += A[(rem / 2) + 1];
	}
	
	cout << fixed << setprecision(9) << ans << '\n';

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
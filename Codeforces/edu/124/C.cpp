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

int T, N, A[mxN], B[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
    	cin >> A[i];
    }
    for(int i = 1; i <= N; i++) {
    	cin >> B[i];
    }

    int ans = abs(A[1] - B[1]) + abs(A[N] - B[N]);
    ans = min(ans, (abs(A[1] - B[N]) + abs(A[N] - B[1])));
    int minDiff1 = INF, minDiff2 = INF, minDiff3 = INF, minDiff4 = INF;
    for(int i = 1; i <= N; i++){
    	if(abs(A[1] - B[i]) < minDiff1) {
    		minDiff1=abs(A[1] - B[i]);
    	}
    	if(abs(B[1] - A[i]) < minDiff2){
    		minDiff2 = abs(B[1] - A[i]);
    	}
    	if(abs(A[N] - B[i]) < minDiff3) {
    		minDiff3=abs(A[N] - B[i]);
    	}
    	if(abs(B[N] - A[i]) < minDiff4){
    		minDiff4 = abs(B[N] - A[i]);
    	}
    }

    ans = min(ans, (minDiff1 + minDiff4 + abs(A[N] - B[1])));
    ans = min(ans, (minDiff3 + minDiff2 + abs(A[1] - B[N])));
    ans = min(ans, (minDiff1 + minDiff2 + abs(A[N] - B[N])));
    ans = min(ans, (abs(A[1] - B[1]) + minDiff3 + minDiff4));
    ans = min(ans, (minDiff1 + minDiff2 + minDiff3 + minDiff4));
    cout << ans << '\n';
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
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

int T, N, X, A[mxN];

void solve()
{
    cin >> N >> X;
    int minElement = INF, maxElement = -INF, ans = 0;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(i > 1){
    		ans += abs(A[i] - A[i - 1]);
    	}
    	minElement = min(minElement, A[i]);
    	maxElement = max(maxElement, A[i]);
    }

    if(minElement > 1){
    	int minSpaceRequiredForRestLeft = A[1] - 1;
    	minSpaceRequiredForRestLeft = min(minSpaceRequiredForRestLeft, A[N] - 1);
    	minSpaceRequiredForRestLeft = min(minSpaceRequiredForRestLeft, 2 * (minElement - 1));

    	ans += minSpaceRequiredForRestLeft;
    }

    if(X > maxElement){
    	int minSpaceRequiredForRestRight = X - A[1];
    	minSpaceRequiredForRestRight = min(minSpaceRequiredForRestRight, X - A[N]);
    	minSpaceRequiredForRestRight = min(minSpaceRequiredForRestRight, 2 * (X - maxElement));

	    ans += minSpaceRequiredForRestRight;
    }

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
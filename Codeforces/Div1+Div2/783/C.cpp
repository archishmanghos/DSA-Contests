#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 5005;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}

	int ans = INF;
	for(int i = 1; i <= N; i++){
		int pre = 0, cnt = 0;
		for(int j = i - 1; j >= 1; j--){
			int dist = 1 - pre;
			int reqd = max((dist + A[j] - 1) / A[j], 1LL);
			pre = -A[j] * reqd;
			cnt += reqd;
		}
		pre = 0;

		for(int j = i + 1; j <= N; j++){
			int dist = pre + 1;
			int reqd = max((dist + A[j] - 1) / A[j], 1LL);
			pre = A[j] * reqd;
			cnt += reqd;
		}
		ans = min(ans, cnt);
	}

	cout << ans;

    return 0;
}
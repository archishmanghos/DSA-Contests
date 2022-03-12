#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 1005;
const int INF = 1e18 + 7;

int N, A[mxN], B[mxN];

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
	for(int i = 1; i <= N; i++){
		cin >> B[i];
	}

	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= N; i++){
		ans1 += A[i] == B[i];
		for(int j = 1; j <= N; j++){
			ans2 += (i != j and A[i] == B[j]);
		}
	}

	cout << ans1 << '\n' << ans2;

    return 0;
}
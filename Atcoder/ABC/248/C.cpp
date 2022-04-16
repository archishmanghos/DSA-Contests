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
const int MOD = 998244353;

int N, M, K;
int cache[55][3000];

int dp(int index, int sumTillNow){
	if(index > N){
		return (sumTillNow <= K ? 1 : 0);
	}
	if(cache[index][sumTillNow] != -1){
		return cache[index][sumTillNow];
	}

	int ans = 0;
	for(int i = 1; i <= M; i++){
		ans = ((ans % MOD) + (dp(index + 1, sumTillNow + i) % MOD)) % MOD;
	}

	return cache[index][sumTillNow] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M >> K;
	memset(cache, -1, sizeof(cache));
	cout << dp(1, 0);

    return 0;
}
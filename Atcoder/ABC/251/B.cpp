#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, W, A[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> W;
    for(int i = 1; i <= N; i++) cin >> A[i];
    vector<bool> flag(W + 2, false);

	for(int i = 1; i <= N; i++) {
		if(A[i] <= W) flag[A[i]] = true;
	}

	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++){
			if(A[i] + A[j] <= W) flag[A[i] + A[j]] = true;
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++){
			for(int k = j + 1; k <= N; k++){
				if(A[i] + A[j] + A[k] <= W) flag[A[i] + A[j] + A[k]] = true;
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= W; i++) ans += flag[i];

	cout << ans;

    return 0;
}
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

int T, N, M;

void solve()
{
    cin >> N >> M;
    char A[N + 2][M + 2];
    for(int i = 1; i <= N; i++) {
    	for(int j = 1; j <= M; j++){
    		cin >> A[i][j];
    	}
    }

    if(N == 1 or M == 1){
    	cout << "YES" << '\n';
    	return;
    }

    bool ans = true;
    for(int i = 1; i < N; i++) {
    	for(int j = 1; j < M; j++) {
    		int cnt = 0;
    		for(int k = i; k <= i + 1; k++){
    			for(int l = j; l <= j + 1; l++){
    				cnt += A[k][l] == '0';
    			}
    		}

    		if(cnt == 1){
    			ans = false;
    			break;
    		}
    	}
    }

    cout << (ans ? "YES" : "NO") << '\n';
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
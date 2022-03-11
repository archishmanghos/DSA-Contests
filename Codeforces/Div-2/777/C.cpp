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
char A[105][105];

void solve()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
    	for(int j = 1; j <= M; j++){
    		cin >> A[i][j];
    	}
    }

    if(A[1][1] == '1'){
    	cout << -1 << '\n';
    	return;
    }

    char B[N + 2][M + 2];
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		B[i][j] = '0';
    	}
    }
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for(int i = N; i >= 1; i--){
    	for(int j = M; j >= 1; j--){
    		if(A[i][j] == '1'){
    			pair<int, int> pair1, pair2;
    			if(i - 1 >= 1){
					pair1 = {i - 1, j};
    				pair2 = {i, j};
    				B[i][j] = '1';
    				ans.push_back({pair1, pair2});
				}else if(j - 1 >= 1){
					pair1 = {i, j - 1};
    				pair2 = {i, j};
    				B[i][j] = '1';
    				ans.push_back({pair1, pair2});
				}else{
					cout << -1 << '\n';
					return;
				}
    		}
    	}
    }

    cout << ans.size() << '\n';
    for(auto i : ans) {
    	cout << i.first.first << ' ' << i.first.second << ' ' << i.second.first << ' ' << i.second.second << '\n';
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
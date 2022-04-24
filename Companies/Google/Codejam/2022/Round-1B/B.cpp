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

int T, N, P;
int cache[1005][105][2];

int dp(int index, int p, int end, vector<vector<int>> &A){

	if(index == N - 1){
		if(end and p == 0){
			return 0;
		}else if(!end and p == P - 1){
			return 0;
		}
	}
	if(cache[index][p][end] != -1){
		return cache[index][p][end];
	}

	int ans = INF;
	if((p == P - 1 and !end) or (p == 0 and end)){
		ans = min(dp(index + 1, 0, 0, A) + abs(A[index][p] - A[index + 1][0]), dp(index + 1, P - 1, 1, A) + abs(A[index][p] - A[index + 1][P - 1]));
	}else{
		if(end){
			ans = dp(index, p - 1, 1, A) + abs(A[index][p] - A[index][p - 1]);
		}else{
			ans = dp(index, p + 1, 0, A) + abs(A[index][p] - A[index][p + 1]);
		}
	}

	return cache[index][p][end] = ans;
}

void solve()
{
    cin >> N >> P;
    vector<vector<int>> A(N);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < P; j++){
    		int X;
    		cin >> X;
    		A[i].push_back(X);
    	}
    	sort(A[i].begin(), A[i].end());
    }

    int ans = min(dp(0, 0, 0, A) + A[0][0], dp(0, P - 1, 1, A) + A[0][P - 1]);
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
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
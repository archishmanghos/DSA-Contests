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

int T, N, K, A[mxN];

void solve() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    A[N + 1] = INF;
    sort(A + 1, A + N + 2);
    int cnt = 1, preCnt = -1;
    vector<pair<int, pair<int, int>>> v;
    pair<int, int> ans = {-1, -1};
    for(int i = 2; i <= N + 1; i++){
    	if(A[i] == A[i - 1]){
    		cnt += 1;
    	}else{
    		if(preCnt != -1 and preCnt >= K){
    			if(cnt >= K){
    				if(ans.second + 1 == A[i - 1]){
    					ans.second += 1;
    				}else{
    					int dist = ans.second - ans.first + 1;
    					v.push_back({dist, ans});
    					ans = {A[i - 1], A[i - 1]};
    				}
    			}else{
    				if(ans.first != -1){
    					int dist = ans.second - ans.first + 1;
    					v.push_back({dist, ans});
    				}
    				ans = {-1, -1};
    			}
    		}else{
    			if(cnt >= K){
    				ans = {A[i - 1], A[i - 1]};
    			}
    		}
    		debug(ans)
    		preCnt = cnt;
    		cnt = 1;
    	}
    }

    if(ans.first != -1){
    	int dist = ans.second - ans.first + 1;
    	debug(dist)
    	v.push_back({dist, ans});
    }

    if(v.size() == 0){
    	cout << -1 << '\n';
    	return;
    }

    sort(v.begin(), v.end());
    cout << v[v.size() - 1].second.first << ' ' << v[v.size() - 1].second.second << '\n';
}

int32_t main() {
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
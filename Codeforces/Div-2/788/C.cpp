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

int T, N, A[mxN], B[mxN], C[mxN];
vector<int> adj[mxN];

void dfs1(int node, vector<bool> &visited, int &sizeOfComponent){
	if(visited[node]){
		return;
	}

	sizeOfComponent += 1;
	visited[node] = true;
	for(int child : adj[node]){
		dfs1(child, visited, sizeOfComponent);
	}
}

void dfs2(int node, vector<bool> &visited){
	if(visited[node]){
		return;
	}

	visited[node] = true;
	for(int child : adj[node]){
		dfs2(child, visited);
	}
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++){
    	adj[i].clear();
    	cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
    	cin >> B[i];
    	adj[A[i]].push_back(B[i]);
    	adj[B[i]].push_back(A[i]);
    }

    vector<bool> visited(N + 2, false);
    for(int i = 1; i <= N; i++){
    	cin >> C[i];
    	if(C[i] != 0){
    		if(C[i] == A[i] and !visited[A[i]]){
    			dfs2(A[i], visited);
    		}else if(C[i] == B[i] and !visited[B[i]]){
    			dfs2(B[i], visited);
    		}
    	}
    }

    int ans = 1, MOD = 1e9 + 7;
    for(int i = 1; i <= N; i++){
    	if(!visited[i]){
    		int sizeOfComponent = 0;
    		dfs1(i, visited, sizeOfComponent);
    		if(sizeOfComponent > 1){
    			ans = ((ans % MOD) * 2) % MOD;
    		}
    	}
    }

    cout << ans << '\n';
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
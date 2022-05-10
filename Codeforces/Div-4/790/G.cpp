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

int T, N, A;
char c;
vector<int> colour(4005);
vector<pair<int, int>> colourNodes(4005);
vector<int> adj[4005];

void dfs(int node, int white, int black, int &ans, vector<bool> &visited){

	colourNodes[node].first = colour[node] == 1 ? 1 : 0;
	colourNodes[node].second = colour[node] == 0 ? 1 : 0;
	visited[node] = true;

	for(int child : adj[node]){
		if(!visited[child]){
			dfs(child, white, black, ans, visited);

			colourNodes[node].first += colourNodes[child].first;
			colourNodes[node].second += colourNodes[child].second;
		}
	}

	ans += colourNodes[node].first == colourNodes[node].second;
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++){
    	adj[i].clear();
    	colourNodes[i] = {0, 0};
    }

    for(int i = 2; i <= N; i++){
    	cin >> A;
    	adj[i].push_back(A);
    	adj[A].push_back(i);
    }

    colour.assign(N + 2, 0);
    int black = 0, white = 0;
    for(int i = 1; i <= N; i++){
    	cin >> c;
    	black += c == 'B';
    	white += c == 'W';
    	if(c == 'B'){
    		colour[i] = 1;
    	}
    }

    vector<bool> visited(N + 2, false);
    int ans = 0;

    dfs(1, 0, 0, ans, visited);
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
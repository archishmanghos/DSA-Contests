#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void dfs(int node, int &cnt, vector<bool> &visited, vector<vector<int>> &adj){
	if(visited[node]){
		return;
	}

	visited[node] = true;
	cnt += 1;
	for(int child : adj[node]){
		dfs(child, cnt, visited, adj);
	}
}

bool presentNode(int node, int &checkNode, vector<bool> &visited, vector<vector<int>> &adj){
	if(visited[node]){
		return false;
	}

	visited[node] = true;
	if(node == checkNode){
		return true;
	}

	bool ans = false;
	for(int child : adj[node]){
		ans |= presentNode(child, checkNode, visited, adj);
	}

	return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D, U, V;
    cin >> N >> D;
    vector<vector<int>> adj(N + 2);
    for(int i = 1; i <= N; i++){
    	adj[i].clear();
    }

    int edgesToBeUsed = 0;
    while(D--){
    	cin >> U >> V;
    	vector<bool> visited(N + 2, false);

    	if(!presentNode(U, V, visited, adj)){
    		adj[U].push_back(V);
    		adj[V].push_back(U);
    	}
    	else{
    		edgesToBeUsed += 1;
    	}

    	visited.assign(N + 2, false);
    	priority_queue<int> componentSize;
    	for(int i = 1; i <= N; i++){
    		if(!visited[i]){
    			int cnt = 0;
    			dfs(i, cnt, visited, adj);
    			componentSize.push(cnt);
    		}
    	}

    	int ans = 0, edge = edgesToBeUsed;
    	ans = componentSize.top();
    	componentSize.pop();
    	while(!componentSize.empty() and edge){
    		ans += componentSize.top();
    		componentSize.pop();
    		edge -= 1;
    	}

    	cout << ans - 1 << '\n';
    }

    return 0;
}
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, set<int> &restricted) {
	if (visited[node]) return;
	if (restricted.find(node) != restricted.end()) return;
	visited[node] = true;
	for (int child : adj[node]) {
		dfs(child, adj, visited, restricted);
	}
}
int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
	vector<vector<int>> adj(n);
	for (auto e : edges) {
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}

	set<int> restrictedNodes;
	for (int i : restricted) restrictedNodes.insert(i);
	vector<bool> visited(n);
	dfs(0, adj, visited, restrictedNodes);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += visited[i] == true;
	}

	return ans;
}
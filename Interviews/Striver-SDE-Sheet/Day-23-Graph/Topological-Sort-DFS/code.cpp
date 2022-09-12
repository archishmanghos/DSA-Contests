void dfs(int node, stack<int> &st, vector<int> &visited, vector<int> *adj) {
	if (visited[node]) return;
	visited[node] = 1;

	for (int child : adj[node]) {
		dfs(child, st, visited, adj);
	}

	st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
	stack<int> st;
	vector<int> ans, visited(V, 0);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			dfs(i, st, visited, adj);
		}
	}

	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
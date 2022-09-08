void dfs(int node, vector<int> *adj, vector<int> &ans, vector<int> &visited) {
    if (visited[node]) return;
    visited[node] = 1;
    ans.push_back(node);
    for (int child : adj[node]) {
        dfs(child, adj, ans, visited);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans, visited(V, 0);
    dfs(0, adj, ans, visited);
    return ans;
}
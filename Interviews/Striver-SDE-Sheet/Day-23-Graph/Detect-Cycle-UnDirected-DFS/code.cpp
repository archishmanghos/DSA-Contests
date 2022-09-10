void dfs(int node, int parent, vector<int> &visited, vector<int> *adj, bool &ans) {
    visited[node] = 1;
    for (int child : adj[node]) {
        if (visited[child]) {
            ans |= child != parent;
        } else {
            dfs(child, node, visited, adj, ans);
        }
    }
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool ans = false;
            dfs(i, -1, visited, adj, ans);
            if (ans) return true;
        }
    }
    return false;
}
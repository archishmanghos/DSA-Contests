void dfs(int node, vector<int> &v, vector<vector<int>> &adj) {
    if (v[node]) return;
    v[node] = 1;
    for (int child : adj[node]) {
        dfs(child, v, adj);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int ans = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans += 1;
            dfs(i, visited, adj);
        }
    }

    return ans;
}
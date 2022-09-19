void dfs(int node, vector<int> &v, vector<vector<int>> &adj) {
    if (v[node]) return;
    v[node] = 1;
    for (int child : adj[node]) {
        dfs(child, v, adj);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j : rooms[i]) {
            adj[i].push_back(j);
        }
    }

    vector<int> visited(n, 0);
    dfs(0, visited, adj);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }

    return true;
}
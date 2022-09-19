void dfs(int node, vector<int> &visited, vector<vector<int>> &adj) {
    if (visited[node]) return;
    visited[node] = 1;
    for (int child : adj[node]) {
        dfs(child, visited, adj);
    }
}
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n), visited(n, 0), ans;
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        indegree[v] += 1;
        adj[u].push_back(v);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({indegree[i], i});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int node = v[i].second;
        if (!visited[node]) {
            ans.push_back(node);
            dfs(node, visited, adj);
        }
    }

    return ans;
}
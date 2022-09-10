bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<vector<int>> &adj) {
    visited[node] = pathVisited[node] = true;

    for (int child : adj[node]) {
        if (visited[child]) {
            if (pathVisited[child]) return true;
        }
        else {
            if (dfs(child, visited, pathVisited, adj)) return true;
        }
    }

    pathVisited[node] = false;
    return false;
}

bool canFinish(int n, vector<vector<int>>& p) {
    vector<vector<int>> adj(n);
    for (auto i : p) {
        int u = i[0], v = i[1];
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0), pathVisited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, pathVisited, adj)) return false;
        }
    }

    return true;
}
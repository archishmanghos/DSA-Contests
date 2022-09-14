void dfs1(int node, vector<int> &t, vector<int> &v, vector<vector<int>> &a) {
    if (v[node]) return;
    v[node] = 1;

    for (int child : a[node]) {
        dfs1(child, t, v, a);
    }

    t.push_back(node);
}

void dfs2(int node, vector<int> &t, vector<int> &v, vector<vector<int>> a) {
    if (v[node]) return;

    v[node] = 1;
    t.push_back(node);
    for (int child : a[node]) {
        dfs2(child, t, v, a);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n), adjTranspose(n);
    for (auto i : edges) {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    vector<int> topo, visited(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, topo, visited, adj);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int child : adj[i]) {
            adjTranspose[child].push_back(i);
        }
    }

    visited.assign(n, 0);
    vector<vector<int>> ans;
    while (topo.size() > 0) {
        if (!visited[topo.back()]) {
            vector<int> temp;
            dfs2(topo.back(), temp, visited, adjTranspose);
            ans.push_back(temp);
        }
        topo.pop_back();
    }

    return ans;
}
#include <bits/stdc++.h>

void dfs(int node, int parent, int &maxx, int dist, vector<int> &visited, vector<vector<int>> &adj) {
    if (visited[node]) return;
    visited[node] = 1;
    if (adj[node].size() == 1 and adj[node][0] == parent) {
        maxx = max(maxx, dist);
        return;
    }

    for (int child : adj[node]) {
        dfs(child, node, maxx, dist + 1, visited, adj);
    }
}

int solution(int N, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(N + 1);
    for (auto i : edges) {
        int u = i.first, v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 2 * int(edges.size()), maxDist = INT_MIN;
    vector<int> visited(N + 1, 0);
    dfs(1, -1, maxDist, 0, visited, adj);
    return (ans - maxDist);
}
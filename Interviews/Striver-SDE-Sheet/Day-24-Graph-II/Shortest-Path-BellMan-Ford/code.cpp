vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (auto edge : adj) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dist[v] = min(dist[v], dist[u] + wt);
        }
    }

    return dist;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> adj[n];
    for (auto edge : flights) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(n + 5, 1e9));
    dist[src][1] = 0;
    int ans = 1e9;
    pq.push({0, src, 1});
    while (!pq.empty()) {
        int u = pq.top()[1], nodes = pq.top()[2];
        pq.pop();
        for (auto child : adj[u]) {
            int v = child[0], wt = child[1], stops = nodes - 2;
            if (dist[v][nodes + 1] > dist[u][nodes] + wt and stops < k) {
                dist[v][nodes + 1] = dist[u][nodes] + wt;
                if (v == dst) ans = min(ans, dist[v][nodes + 1]);
                pq.push({dist[v][nodes + 1], v, nodes + 1});
            }
        }
    }

    return (ans < 1e9 ? ans : -1);
}
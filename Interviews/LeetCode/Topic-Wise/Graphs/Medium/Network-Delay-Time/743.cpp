int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>> adj[n];
    for (auto edge : times) {
        int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
        adj[u].push_back({v, w});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, k - 1});
    vector<int> dist(n, 1e9);
    dist[k - 1] = 0;
    while (!pq.empty()) {
        int curNode = pq.top()[1], wt = pq.top()[0];
        pq.pop();
        for (auto child : adj[curNode]) {
            if (dist[child[0]] > dist[curNode] + child[1]) {
                dist[child[0]] = dist[curNode] + child[1];
                pq.push({dist[child[0]], child[0]});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }

    return (ans < 1e9 ? ans : -1);
}
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty()) {
        int curNode = pq.top().second, curDist = pq.top().first;
        pq.pop();

        for (auto i : adj[curNode]) {
            int child = i[0], childDist = i[1];
            if (dist[child] > dist[curNode] + childDist) {
                dist[child] = dist[curNode] + childDist;
                pq.push({dist[child], child});
            }
        }
    }

    return dist;
}
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> key(V, 1e9), parent(V, -1), mst(V, 0);
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int minNode = pq.top().second;
        pq.pop();
        mst[minNode] = 1;
        for (vector<int> u : adj[minNode]) {
            int child = u[0], wt = u[1];
            if (mst[child]) continue;
            if (key[child] > wt) {
                key[child] = wt;
                parent[child] = minNode;
                pq.push({key[child], child});
            }
        }
    }

    int mstCost = 0;
    for (int i : key) mstCost += i;

    return mstCost;
}
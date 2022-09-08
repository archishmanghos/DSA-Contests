bool canFinish(int n, vector<vector<int>>& p) {
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for (auto i : p) {
        int u = i[0], v = i[1];
        indegree[u] += 1;
        adj[v].push_back(u);
    }

    queue<int> kahn;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            kahn.push(i);
        }
    }

    while (!kahn.empty()) {
        int curNode = kahn.front();
        kahn.pop();
        n -= 1;
        for (int child : adj[curNode]) {
            if (indegree[child] == 0) continue;
            indegree[child] -= 1;
            if (indegree[child] == 0) {
                kahn.push(child);
            }
        }
    }

    return n == 0;
}
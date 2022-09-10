bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            while (!q.empty()) {
                int curNode = q.front().first;
                int curParent = q.front().second;
                q.pop();
                visited[curNode] = 1;

                for (int child : adj[curNode]) {
                    if (visited[child]) {
                        if (child != curParent) return true;
                    } else {
                        q.push({child, curNode});
                    }
                }
            }
        }
    }
    return false;
}
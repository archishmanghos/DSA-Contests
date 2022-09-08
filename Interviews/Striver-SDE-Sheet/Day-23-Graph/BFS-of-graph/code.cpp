vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans, visited(V, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int curNode = q.front();
        q.pop();
        if (visited[curNode]) continue;
        visited[curNode] = 1;
        ans.push_back(curNode);
        for (int child : adj[curNode]) {
            q.push(child);
        }
    }

    return ans;
}
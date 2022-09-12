bool isBipartite(vector<vector<int>>& adj) {
    queue<int> q;
    int n = adj.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++) {
        if (colour[i] == -1) {
            q.push(i);
            colour[i] = 0;
            while (!q.empty()) {
                int curNode = q.front();
                q.pop();
                for (int child : adj[curNode]) {
                    if (colour[child] != -1 and colour[child] == colour[curNode]) {
                        return false;
                    } else if (colour[child] == -1) {
                        colour[child] = !colour[curNode];
                        q.push(child);
                    }
                }
            }
        }
    }

    return true;
}
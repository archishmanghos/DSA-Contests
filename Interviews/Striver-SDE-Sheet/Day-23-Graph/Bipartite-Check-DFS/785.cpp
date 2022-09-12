bool check(int node, vector<vector<int>> &adj, vector<int> &colour) {
    for (int child : adj[node]) {
        if (colour[child] != -1 and colour[child] == colour[node]) return false;
        if (colour[child] == -1) {
            colour[child] = !colour[node];
            if (!check(child, adj, colour)) return false;
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++) {
        if (colour[i] == -1) {
            colour[i] = 0;
            if (!check(i, adj, colour)) return false;
        }
    }

    return true;
}
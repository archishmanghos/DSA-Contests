bool equationsPossible(vector<string>& equations) {
    vector<set<int>> adj(26), notAdj(26);
    for (string s : equations) {
        int u = s[0] - 'a', v = s[3] - 'a';
        if (s[1] == '=') {
            if (u == v) continue;
            if (notAdj[u].find(v) != notAdj[u].end()) {
                return false;
            }
            for (int child : adj[u]) {
                if (notAdj[child].find(v) != notAdj[child].end()) {
                    return false;
                }
                adj[child].insert(v);
                adj[v].insert(child);
            }
            adj[u].insert(v);
            for (int child : adj[v]) {
                if (notAdj[child].find(u) != notAdj[child].end()) {
                    return false;
                }
                adj[child].insert(u);
                adj[u].insert(child);
            }
            adj[v].insert(u);
        } else {
            if (u == v) return false;
            if (adj[u].find(v) != adj[u].end()) {
                return false;
            }
            for (int child : adj[u]) {
                if (adj[child].find(v) != adj[child].end()) {
                    return false;
                }
                notAdj[child].insert(v);
                notAdj[v].insert(child);
            }
            notAdj[u].insert(v);
            for (int child : adj[v]) {
                if (adj[child].find(u) != adj[child].end()) {
                    return false;
                }
                notAdj[child].insert(u);
                notAdj[u].insert(child);
            }
            notAdj[v].insert(u);
        }
    }

    return true;
}
void dfs(int curNode, stack<int> &st, vector <set<int>> &adj, vector<bool> &visited) {
    if (visited[curNode]) {
        return;
    }

    visited[curNode] = true;
    for (int child: adj[curNode]) {
        dfs(child, st, adj, visited);
    }

    st.push(curNode);
}

vector <vector<int>> getAncestors(int n, vector <vector<int>> &edges) {
    vector <set<int>> ans(n);
    vector <set<int>> adj(n);
    for (auto i: edges) {
        adj[i[0]].insert(i[1]);
    }
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        dfs(i, st, adj, visited);
    }
    vector<int> topoSort;
    while (!st.empty()) {
        topoSort.push_back(st.top());
        st.pop();
    }

    for (int i = 1; i < topoSort.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (adj[topoSort[j]].find(topoSort[i]) != adj[topoSort[j]].end()) {
                ans[topoSort[i]].insert(topoSort[j]);
                for (int it: ans[topoSort[j]]) {
                    ans[topoSort[i]].insert(it);
                }
            }
        }
    }
    vector <vector<int>> finalAns(n);
    for (int i = 0; i < n; i++) {
        for (int j: ans[i]) {
            finalAns[i].push_back(j);
        }
    }
    return finalAns;
}
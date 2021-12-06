void dfs(vector<vector<int>> &ans, vector<int> v, int node, vector<vector<int>> &adj, int &n)
{
    if(node == n - 1)
    {
        ans.push_back(v);
        return;
    }

    for(int child : adj[node])
    {
        v.push_back(child);
        dfs(ans, v, child, adj, n);
        v.pop_back();
    }

    if(node == 0)
        return;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
            adj[i].push_back(graph[i][j]);
    }

    vector<vector<int>> ans;
    vector<int> v = {0};
    dfs(ans, v, 0, adj, n);
    return ans;
}
void dfs(int node, int parent, vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>> &adj, vector<vector<int>> &ans)
{
    tin[node] = low[node] = timer;
    timer += 1;
    visited[node] = true;

    for(int child : adj[node])
    {
        if(child == parent)
            continue;
        if(visited[child])
            low[node] = min(low[node], tin[child]);
        else
        {
            dfs(child, node, visited, tin, low, timer, adj, ans);
            low[node] = min(low[node], low[child]);

            if(low[child] > tin[node])
            {
                vector<int> temp = {node, child};
                ans.push_back(temp);
            }
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);
    for(int i = 0; i < connections.size(); i++)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    vector<vector<int>> ans;
    vector<bool> visited(n + 2, false);
    vector<int> tin(n + 2), low(n + 2);
    int timer = 1;
    dfs(0, -1, visited, tin, low, timer, adj, ans);

    return ans;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n + 2, 0), adj[n + 5], ans;
    if(n == 1)
    {
        ans.push_back(0);
        return ans;
    }
    for(int i = 1; i <= n - 1; i++)
    {
        adj[edges[i - 1][0]].push_back(edges[i - 1][1]);
        adj[edges[i - 1][1]].push_back(edges[i - 1][0]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        degree[edges[i][0]] += 1;
        degree[edges[i][1]] += 1;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(degree[i] == 1)
            q.push(i);
    }

    while((int)q.size() > 1)
    {
        bool allOne = true;
        for(int i = 0; i < n; i++)
            allOne &= degree[i] <= 1;
        if(allOne)
            break;
        int sz = q.size();
        for(int i = 1; i <= sz; i++)
        {
            int curNode = q.front();
            q.pop();
            degree[curNode] -= 1;

            for(int node : adj[curNode])
            {
                degree[node] -= 1;
                if(degree[node] == 1)
                    q.push(node);
            }
        }
    }

    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}
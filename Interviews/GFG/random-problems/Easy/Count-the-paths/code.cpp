void dfs(int node, int &ans, int &d, vector<vector<int>> &adj){
    if(node == d){
        ans += 1;
        return;
    }
    
    for(int child : adj[node]) dfs(child, ans, d, adj);
}
int possible_paths(vector<vector<int>>edges, int n, int s, int d){
    vector<vector<int>> adj(n);
    for(auto i : edges) adj[i[0]].push_back(i[1]);
    
    int ans = 0;
    dfs(s, ans, d, adj);
    return ans;
}
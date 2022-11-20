class Solution {
   public:
    long long dfs(int node, int seats, vector<int>& vis, vector<vector<int>>& adj, long long& fuel) {
        vis[node] = 1;
        long long childs = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            if (!vis[adj[node][i]]) {
                childs += dfs(adj[node][i], seats, vis, adj, fuel);
            }
        }

        if (node != 0) {
            fuel += (childs + seats - 1) / seats;
        }
        return childs;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        long long fuel = 0;
        long long childs = dfs(0, seats, vis, adj, fuel);
        return fuel;
    }
};
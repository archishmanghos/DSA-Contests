int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(auto j : edges){
            int u = j[0], v = j[1], w = j[2];
            if(dist[u] != INT_MAX){
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    
    for(auto j : edges){
        int u = j[0], v = j[1], w = j[2];
        if(dist[v] > dist[u] + w){
            return 1;
        }
    }
    
    return 0;
}
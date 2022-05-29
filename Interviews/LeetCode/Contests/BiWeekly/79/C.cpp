long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> degree(n, 0);
    for(auto i : roads){
        int u = i[0], v = i[1];
        degree[u] += 1;
        degree[v] += 1;
    }
    
    vector<pair<int, int>> nodes;
    for(int i = 0; i < n; i++) nodes.push_back({degree[i], i});
    
    sort(nodes.begin(), nodes.end());
    vector<int> values(n, 0);
    for(int i = 0; i < n; i++) values[nodes[i].second] = i + 1;
    
    long long ans = 0;
    for(auto i : roads){
        int u = i[0], v = i[1];
        ans += values[u] + values[v];
    }
    
    return ans;
}
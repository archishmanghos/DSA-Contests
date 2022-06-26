vector<long long> adj[100005];
void dfs(long long node, long long &sz, vector<bool> &visited){
    if(visited[node]) return;
    sz += 1;
    visited[node] = true;
    for(long long child : adj[node]){
        dfs(child, sz, visited);
    }
}
long long countPairs(int n, vector<vector<int>>& edges) {
    for(long long i = 0; i < n; i++) adj[i].clear();
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> visited(n, false);
    vector<long long> componentSize;
    for(long long i = 0; i < n; i++){
        if(!visited[i]){
            long long sz = 0;
            dfs(i, sz, visited);
            componentSize.push_back(sz);
        }
    }

    long long m = componentSize.size(), sum = 0;
    vector<long> suffixArr(m, 0);
    for(long long i = m - 1; i >= 0; i--){
        sum += componentSize[i];
        suffixArr[i] = sum;
    }

    long long ans = 0;
    for(long long i = 0; i < m - 1; i++){
        ans += componentSize[i] * suffixArr[i + 1];
    }

    return ans;
}
int dp(int index, int cityA, int &n, vector<vector<int>> &costs, vector<vector<int>> &cache){
    if(index >= n){
        return 0;
    }
    if(cache[index][cityA] != -1){
        return cache[index][cityA];
    }
    
    int ans;
    if(cityA < (n / 2)){
        int reqdMore = (n / 2) - cityA;
        int leftToSelect = n - index;
        if(reqdMore < leftToSelect){
            ans = min(dp(index + 1, cityA + 1, n, costs, cache) + costs[index][0], dp(index + 1, cityA, n, costs, cache) + costs[index][1]);
        }else{
            ans = dp(index + 1, cityA + 1, n, costs, cache) + costs[index][0];
        }
    }else{
        ans = dp(index + 1, cityA, n, costs, cache) + costs[index][1];
    }
    return cache[index][cityA] = ans;
}
int twoCitySchedCost(vector<vector<int>> &costs){
    int n = costs.size();
    vector<vector<int>> cache(n + 2, vector<int>((n / 2) + 2, -1));
    return dp(0, 0, n, costs, cache);
}
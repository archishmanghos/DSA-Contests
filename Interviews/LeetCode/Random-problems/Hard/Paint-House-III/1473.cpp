int dp(int index, int pre, int target, int &n, int &m, vector<int> &houses, vector<vector<int>> &cost, vector<vector<vector<int>>> &cache){
    if(index == m){
        return target == 0 ? 0 : 1000005;
    }
    if(target < 0) return 1000005;
    if(cache[index][pre][target] != -1) return cache[index][pre][target];
    int ans = 1000005;

    if(houses[index] != 0){
        if(pre == houses[index]) ans = dp(index + 1, houses[index], target, n, m, houses, cost, cache);
        else ans = dp(index + 1, houses[index], target - 1, n, m, houses, cost, cache);
    }else{
        if(target){
            for(int i = 1; i <= n; i++){
                if(i == pre) ans = min(ans, (int)dp(index + 1, i, target, n, m, houses, cost, cache) + cost[index][i - 1]);
                else ans = min(ans, (int)dp(index + 1, i, target - 1, n, m, houses, cost, cache) + cost[index][i - 1]);
            }
        }else{
            ans = (int)dp(index + 1, pre, target, n, m, houses, cost, cache) + cost[index][pre - 1];
        }
    }

    return cache[index][pre][target] = ans;
}
int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target){
    vector<vector<vector<int>>> cache(m + 2, vector<vector<int>>(n + 2, vector<int>(target + 2, -1)));
    int ans = dp(0, 0, target, n, m, houses, cost, cache);
    if(ans == 1000005) return -1;
    else return ans;
}
int dp(int index, int k, int &n, vector<vector<int>> &piles, vector<vector<int>> &cache){
    if(index >= n){
        return 0;
    }
    if(cache[index][k] != -1){
        return cache[index][k];
    }
    
    int ans = dp(index + 1, k, n, piles, cache), sum = 0;
    for(int i = 0; i < piles[index].size(); i++){
        sum += piles[index][i];
        if(k - i > 0){
            ans = max(ans, dp(index + 1, k - i - 1, n, piles, cache) + sum);
        }else{
            break;
        }
    }
    return cache[index][k] = ans;
}
int maxValueOfCoins(vector<vector<int>> &piles, int k){
    int n = piles.size();
    vector<vector<int>> cache(n + 2, vector<int>(k + 2, -1));
    return dp(0, k, n, piles, cache);
}
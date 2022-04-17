pair<int, int> cntOfFiveandTwo(int x){
    int five = 0, two = 0;
    while(x % 5 == 0){
        five += 1;
        x /= 5;
    }
    while(x % 2 == 0){
        two += 1;
        x >>= 1;
    }
    return {two, five};
}
int maxTrailingZeros(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<pair<pair<int, int>, pair<int, int>>>> proGrid(n, vector<pair<pair<int, int>, pair<int, int>>>(m));
    
    pair<int, int> twoFive = {0, 0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pair<int, int> twoFive = cntOfFiveandTwo(grid[i][j]);
            if(i == 0){
                proGrid[i][j].first = twoFive;
            }else{
                proGrid[i][j].first = {proGrid[i - 1][j].first.first + twoFive.first, proGrid[i - 1][j].first.second + twoFive.second};
            }
            
            if(j == 0){
                proGrid[i][j].second = twoFive;
            }else{
                proGrid[i][j].second = {proGrid[i][j - 1].second.first + twoFive.first, proGrid[i][j - 1].second.second + twoFive.second};
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int two = proGrid[i][j].first.first + (j > 0 ? proGrid[i][j - 1].second.first : 0);
            int five = proGrid[i][j].first.second + (j > 0 ? proGrid[i][j - 1].second.second : 0);
            ans = max(ans, min(two, five));
            
            two = (proGrid[n - 1][j].first.first - proGrid[i][j].first.first) + proGrid[i][j].second.first;
            five = (proGrid[n - 1][j].first.second - proGrid[i][j].first.second) + proGrid[i][j].second.second;
            ans = max(ans, min(two, five));
            
            two = proGrid[i][j].first.first + (proGrid[i][m - 1].second.first - proGrid[i][j].second.first);
            five = proGrid[i][j].first.second + (proGrid[i][m - 1].second.second - proGrid[i][j].second.second);
            ans = max(ans, min(two, five));
            
            two = (proGrid[n - 1][j].first.first - (i > 0 ? proGrid[i - 1][j].first.first : 0)) + (proGrid[i][m - 1].second.first - proGrid[i][j].second.first);
            five = (proGrid[n - 1][j].first.second - (i > 0 ? proGrid[i - 1][j].first.second : 0)) + (proGrid[i][m - 1].second.second - proGrid[i][j].second.second);
            ans = max(ans, min(two, five));
        }
    }
    
    return ans;
}
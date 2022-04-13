bool checkValid(int x, int y, int n){
    return (x >= 0 and x<n and y >= 0 and y < n);
}

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> ans(n, vector<int> (n, -1));
    int j = 1, k = 0, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    pair<int, int> start = {0, 0};
    
    while(true){
        ans[start.first][start.second] = j++;
        
        if(checkValid(start.first + dx[k], start.second + dy[k], n) and ans[start.first + dx[k]][start.second + dy[k]] == -1){
            start = {start.first + dx[k], start.second + dy[k]};
        }else if(checkValid(start.first + dx[(k + 1) % 4], start.second + dy[(k + 1) % 4], n) and ans[start.first + dx[(k + 1) % 4]][start.second + dy[(k + 1) % 4]] == -1){
            start = {start.first + dx[(k + 1) % 4], start.second + dy[(k + 1) % 4]};
            k = (k + 1) % 4;
        }else{
            break;
        }
    }
    
    return ans;
}
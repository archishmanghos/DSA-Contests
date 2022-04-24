bool checkValid(pair<int, int> index, int n, int m){
    return (index.first >= 0 and index.first<n and index.second >= 0 and index.second < m);
}
int shortestPathBinaryMatrix(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ans = 0;
    vector<vector<int>> visited(n, vector<int>(m, false));
    
    while(!q.empty()){
        int sz = q.size();
        ans += 1;
        for(int i = 1; i <= sz; i++){
            pair<int, int> curCell = q.front();
            q.pop();
            if(!checkValid(curCell, n, m) or visited[curCell.first][curCell.second] or grid[curCell.first][curCell.second] == 1){
                continue;
            }
            
            visited[curCell.first][curCell.second] = true;
            if(curCell.first == n - 1 and curCell.second == m - 1){
                return ans;
            }
            
            for(int i = 0; i < 8; i++){
                q.push({curCell.first + dx[i], curCell.second + dy[i]});
            }
        }
    }
    
    return -1;
}
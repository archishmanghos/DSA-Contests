bool isValidIndex(pair<int, int> cell, int n, int m){
    return (cell.first >= 0 and cell.first<n and cell.second >= 0 and cell.second < m);
}

int minimumObstacles(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    vector<vector<int>> dist(n, vector<int>(m, int(1e7)));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    
    while(!pq.empty()){
        pair<int, int> curCell = pq.top().second;
        int obstaclesToCurCell = pq.top().first;
        pq.pop();
        
        if(curCell.first == n - 1 and curCell.second == m - 1) return obstaclesToCurCell;
        
        for(int i = 0; i < 4; i++){
            pair<int, int> nextCell = {curCell.first + dx[i], curCell.second + dy[i]};
            if(!isValidIndex(nextCell, n, m)) continue;
            
            if(dist[nextCell.first][nextCell.second] > grid[nextCell.first][nextCell.second] + obstaclesToCurCell){
                dist[nextCell.first][nextCell.second] = grid[nextCell.first][nextCell.second] + obstaclesToCurCell;
                pq.push({dist[nextCell.first][nextCell.second], nextCell});
            }
        }
    }
    
    return -1;
}
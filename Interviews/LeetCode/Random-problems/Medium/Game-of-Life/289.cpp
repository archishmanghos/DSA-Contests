bool checkValid(int x, int y, int n, int m){
    if(x<0 or x >= n or y<0 or y >= m){
        return false;
    }
    
    return true;
}
void gameOfLife(vector<vector<int>> &board){
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int n = board.size(), m = board[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int dead = 0, live = 0;
            for(int k = 0; k < 8; k++){
                if(checkValid(i + dx[k], j + dy[k], n, m)){
                    dead += board[i + dx[k]][j + dy[k]] <= 0;
                    live += board[i + dx[k]][j + dy[k]] > 0;
                }
            }
            if((board[i][j] == 1 and (live == 2 or live == 3)) or (board[i][j] == 0 and live == 3)){
                board[i][j] = (board[i][j] == 0 ? -1 : 1);
            }else{
                board[i][j] = (board[i][j] == 0 ? 0 : 2);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 2){
                board[i][j] = 0;
            }else if(board[i][j] == -1){
                board[i][j] = 1;
            }
        }
    }
}
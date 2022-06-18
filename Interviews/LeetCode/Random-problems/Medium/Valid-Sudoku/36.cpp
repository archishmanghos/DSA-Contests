bool checkvalid(vector<vector<char>> &board, int limit11, int limit12, int limit21, int limit22){
    vector<int> count(10, 1);
    for(int i = limit11; i < limit12; i++) {
        for(int j = limit21; j < limit22; j++) {
            if(board[i][j] == '.') continue;
            if(!count[board[i][j] - '0']) return false;
            count[board[i][j] - '0'] -= 1;
        }
    }

    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    bool isValid = true;
    vector<int> countRow(10), countColumn(10);
    for(int i = 0; i < 9; i++) {
        countRow.assign(10, 1), countColumn.assign(10, 1);
        for(int j = 0; j < 9; j++) {
            if(i % 3 == 0 and j % 3 == 0) isValid &= checkvalid(board, i, i + 3, j, j + 3);

            if(board[i][j] != '.') {
                isValid &= countRow[board[i][j] - '0'] > 0;
                countRow[board[i][j] - '0'] -= 1;
            }
            
            if(board[j][i] != '.') {
                isValid &= countColumn[board[j][i] - '0'] > 0;
                countColumn[board[j][i] - '0'] -= 1;
            }
        }
    }

    return isValid;
}
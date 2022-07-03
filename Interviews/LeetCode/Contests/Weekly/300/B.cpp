bool isValid(pair<int, int> curCell, int n, int m){
	return (curCell.first >= 0 and curCell.first<m and curCell.second >= 0 and curCell.second < n);
}

pair<int, int> fillMatrix(vector<vector<int>> &matrix, pair<int, int> curCell, char &dir, int val, int m, int n, vector<vector<bool>> &visited){
	matrix[curCell.first][curCell.second] = val;
	visited[curCell.first][curCell.second] = true;
	if(dir == 'l' and curCell.second > 0 and !visited[curCell.first][curCell.second - 1]){
		curCell.second -= 1;
		return curCell;
	}
	if(dir == 'r' and curCell.second < n - 1 and !visited[curCell.first][curCell.second + 1]){
		curCell.second += 1;
		return curCell;
	}
	if(dir == 'u' and curCell.first > 0 and !visited[curCell.first - 1][curCell.second]){
		curCell.first -= 1;
		return curCell;
	}
	if(dir == 'd' and curCell.first < m - 1 and !visited[curCell.first + 1][curCell.second]){
		curCell.first += 1;
		return curCell;
	}

	pair<int, int> left = {curCell.first, curCell.second - 1};
	pair<int, int> right = {curCell.first, curCell.second + 1};
	pair<int, int> up = {curCell.first - 1, curCell.second};
	pair<int, int> down = {curCell.first + 1, curCell.second};

	if(isValid(left, n, m) and !visited[left.first][left.second] and dir != 'r'){
		dir = 'l';
		return left;
	}
	if(isValid(right, n, m) and !visited[right.first][right.second] and  dir != 'l'){
		dir = 'r';
		return right;
	}
	if(isValid(up, n, m) and !visited[up.first][up.second] and dir != 'd'){
		dir = 'u';
		return up;
	}
	if(isValid(down, n, m) and !visited[down.first][down.second] and dir != 'u'){
		dir = 'd';
		return down;
	}

	return {-1, -1};
}
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    pair<int, int> curCell = {0, 0};
    vector<vector<int>> ans(m, vector<int>(n, -1));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    char dir = 'r';

    while(head){
    	curCell = fillMatrix(ans, curCell, dir, head->val, m, n, visited);
    	head = head->next;
    }

    return ans;
}
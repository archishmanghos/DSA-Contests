int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat){
	vector<vector<bool>> visited(n, vector<bool> (m, false));
	int ans = 0;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{r, c}, {u, d}});
	
	while(!q.empty()){
	    pair<int, int> curCell = q.front().first;
	    pair<int, int> upDown = q.front().second;
	    q.pop();
	    if(curCell.first<0 or curCell.first >= n or curCell.second<0 or curCell.second >= m or mat[curCell.first][curCell.second] == '#' or visited[curCell.first][curCell.second]){
	        continue;
	    }
	    
	    visited[curCell.first][curCell.second] = true;
	    ans += 1;
	    q.push({{curCell.first, curCell.second - 1}, {upDown.first, upDown.second}});
	    q.push({{curCell.first, curCell.second + 1}, {upDown.first, upDown.second}});
	    if(upDown.first){
	        q.push({{curCell.first - 1, curCell.second}, {upDown.first - 1, upDown.second}});
	    }
	    if(upDown.second){
	        q.push({{curCell.first + 1, curCell.second}, {upDown.first, upDown.second - 1}});
	    }
	}
	return ans;
}
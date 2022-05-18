vector < vector < int > > mapMist(int n, int m, vector < vector < int > > mat) {
	  vector<vector<int>> mistMap(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
						if(mat[i][j] == 0) mistMap[i][j] = 1;
				}
		}
		
		return mistMap;
}
bool endOfGrid(int x, int y, int n, int m){
   return (x == n and y == m);
}

bool isValid(int x, int y, int n, int m){
   return (x > 0 and x <= n and y > 0 and y <= m);
}

int dp(int indexX, int indexY, int &n, int &m, int &k, vector<vector<int>> &cache){
   if(!isValid(indexX, indexY, n, m)) return int(1e8);
   if(endOfGrid(indexX, indexY, n, m)) return 0;
   if(cache[indexX][indexY] != -1) return cache[indexX][indexY];

   int ans = min(dp(indexX + 1, indexY, n, m, k, cache) + indexY *k, dp(indexX, indexY + 1, n, m, k, cache) + indexX *k);
   return cache[indexX][indexY] = ans;
}

int endOfMaze(int n, int m, int k){
   vector<vector<int>> cache(n + 2, vector<int>(m + 2, -1));
   return dp(1, 1, n, m, k, cache);
}
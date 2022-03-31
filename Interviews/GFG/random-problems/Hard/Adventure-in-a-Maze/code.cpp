const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
bool checkNotValid(int i, int j, int n){
    return (i<0 or i >= n or j<0 or j >= n);
}
bool checkIfEnd(int i, int j, int n){
    return (i == n - 1 and j == n - 1);
}
int dp1(int i, int j, int &n, vector<vector<int>> &matrix, vector<vector<int>> &cache1){
    if(checkNotValid(i, j, n)){
        return 0;
    }
    if(checkIfEnd(i, j, n)){
        return 1;
    }
    
    int &ans = cache1[i][j];
    if(ans != -1){
        return ans;
    }
    
    if(matrix[i][j] == 1){
        ans = (dp1(i, j + 1, n, matrix, cache1)) % MOD;
    }else if(matrix[i][j] == 2){
        ans = (dp1(i + 1, j, n, matrix, cache1)) % MOD;
    }else{
        ans = ((dp1(i, j + 1, n, matrix, cache1)) % MOD + (dp1(i + 1, j, n, matrix, cache1)) % MOD) % MOD;
    }
    return ans;
}

int dp2(int i, int j, int &n, vector<vector<int>> &matrix, vector<vector<int>> &cache2){
    if(checkNotValid(i, j, n)){
        return -INF;
    }
    if(checkIfEnd(i, j, n)){
        return matrix[n - 1][n - 1];
    }
    
    int &ans = cache2[i][j];
    if(ans != -1){
        return ans;
    }
    
    if(matrix[i][j] == 1){
        ans = dp2(i, j + 1, n, matrix, cache2) + 1;
    }else if(matrix[i][j] == 2){
        ans = dp2(i + 1, j, n, matrix, cache2) + 2;
    }else{
        ans = max(dp2(i, j + 1, n, matrix, cache2), dp2(i + 1, j, n, matrix, cache2)) + 3;
    }
    
    return ans;
}

vector<int> FindWays(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> cache1(n + 2, vector<int>(n + 2, -1));
    vector<vector<int>> cache2(n + 2, vector<int>(n + 2, -1));
    vector<int> ans = {dp1(0, 0, n, matrix, cache1)};
    int maxAdventure = dp2(0, 0, n, matrix, cache2);
    ans.push_back((maxAdventure > 0 ? maxAdventure : 0));
    
    return ans;
}
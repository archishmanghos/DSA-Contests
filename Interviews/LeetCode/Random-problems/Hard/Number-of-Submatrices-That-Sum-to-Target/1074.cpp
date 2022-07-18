int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prefSum(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = i > 0 ? prefSum[i - 1][j] : 0;
            int left = j > 0 ? prefSum[i][j - 1] : 0;
            int diagonal = i > 0 and j > 0 ? prefSum[i - 1][j - 1] : 0;
            prefSum[i][j] = up + left + matrix[i][j] - diagonal;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int totalSum = prefSum[k][l];
                    int leftSum = j > 0 ? prefSum[k][j - 1] : 0;
                    int upSum = i > 0 ? prefSum[i - 1][l] : 0;
                    int diagonalSum = i > 0 and j > 0 ? prefSum[i - 1][j - 1] : 0;
                    int sum = totalSum - leftSum - upSum + diagonalSum;
                    ans += sum == target;
                }
            }
        }
    }

    return ans;
}
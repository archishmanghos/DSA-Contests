class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int sum = 0;
                for (int k = i; k < i + 3; k++) {
                    if (k != (i + 1)) {
                        for (int l = j; l < j + 3; l++) {
                            sum += grid[k][l];
                        }
                    } else {
                        sum += grid[k][j + 1];
                    }
                }
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
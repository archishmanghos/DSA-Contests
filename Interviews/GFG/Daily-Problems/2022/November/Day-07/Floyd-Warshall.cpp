class Solution {
   public:
    void shortest_distance(vector<vector<int>>& d) {
        int n = d.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k] != -1 and d[k][j] != -1) {
                        if (d[i][j] == -1 or d[i][j] > d[i][k] + d[k][j]) {
                            d[i][j] = d[i][k] + d[k][j];
                        }
                    }
                }
            }
        }
    }
};
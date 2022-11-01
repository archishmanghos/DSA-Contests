class Solution {
public:
    int median(vector<vector<int>> &matrix, int R, int C) {
        vector<int> a(R * C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                a[i * C + j] = matrix[i][j];
            }
        }
        sort(a.begin(), a.end());
        return a[(R * C) / 2];
    }
};
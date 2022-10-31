class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int dx[2] = { -1, 0}, dy[2] = {0, 1}, n = matrix.size(), m = matrix[0].size(), i = 0;
        vector<int> cell = {n - 1, 0};
        auto check = [&](int r, int c) {
            int content = matrix[r][c];
            while (r < n and c < m) {
                if (matrix[r][c] != content) return false;
                r += 1;
                c += 1;
            }

            return true;
        };

        while (cell[1] < m) {
            if (!check(cell[0], cell[1])) return false;
            if (cell[0] == 0 and cell[1] == 0) i += 1;
            cell = {cell[0] + dx[i], cell[1] + dy[i]};
        }

        return true;
    }
};
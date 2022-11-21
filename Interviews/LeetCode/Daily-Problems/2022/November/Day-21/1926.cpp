class Solution {
   public:
    bool checkLastCell(vector<int> cell, int n, int m) {
        return cell[0] == 0 or cell[1] == 0 or cell[0] == n - 1 or cell[1] == m - 1;
    }

    bool checkOutOfGrid(vector<int> cell, int n, int m) {
        return cell[0] < 0 or cell[1] < 0 or cell[0] == n or cell[1] == m;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size(), dist = 0;
        queue<vector<int>> q;
        vector<int> vis(n * m, 0);
        q.push(entrance);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                vector<int> curCell = q.front();
                q.pop();
                if (checkOutOfGrid(curCell, n, m) or vis[curCell[0] * m + curCell[1]] or maze[curCell[0]][curCell[1]] == '+') {
                    continue;
                }

                if (checkLastCell(curCell, n, m) and curCell != entrance) {
                    return dist;
                }

                vis[curCell[0] * m + curCell[1]] = 1;
                int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
                for (int j = 0; j < 4; j++) {
                    vector<int> newCell = {curCell[0] + dx[j], curCell[1] + dy[j]};
                    q.push(newCell);
                }
            }

            dist += 1;
        }

        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int dy[3] = { -1, 0, 1};
    vector<vector<int>> preCache(m, vector<int>(m, 0));
    for (int posX = n - 1; posX >= 0; posX--) {
        vector<vector<int>> curCache(m, vector<int>(m, 0));
        for (int posY1 = m - 1; posY1 >= 0; posY1--) {
            for (int posY2 = m - 1; posY2 >= 0; posY2--) {
                if (posX == n - 1) {
                    curCache[posY1][posY2] = (posY1 == posY2 ? grid[posX][posY1] : grid[posX][posY1] + grid[posX][posY2]);
                } else {
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            int newJ1 = posY1 + dy[k], newJ2 = posY2 + dy[l];
                            if (newJ1 >= 0 and newJ1<m and newJ2 >= 0 and newJ2 < m) {
                                curCache[posY1][posY2] = max(curCache[posY1][posY2], preCache[newJ1][newJ2] + (posY1 == posY2 ? grid[posX][posY1] : grid[posX][posY1] + grid[posX][posY2]));
                            }
                        }
                    }
                }
            }
        }
        preCache = curCache;
    }

    cout << preCache[0][m - 1];
    return 0;
}
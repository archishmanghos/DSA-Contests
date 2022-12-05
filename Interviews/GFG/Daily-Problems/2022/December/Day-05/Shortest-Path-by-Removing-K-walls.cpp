#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        queue<vector<int>> q;
        q.push({0, 0, k});
        vector<int> visited(n * m, -1);

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                int r = q.front()[0], c = q.front()[1], k = q.front()[2];
                q.pop();
                if (r == n - 1 and c == m - 1) {
                    return ans;
                }

                if (r < 0 or r >= n or c < 0 or c >= m) {
                    continue;
                }

                if (mat[r][c] == 1) {
                    if (k > 0) {
                        k -= 1;
                    } else {
                        continue;
                    }
                }

                if (visited[r * m + c] != -1 and visited[r * m + c] >= k) {
                    continue;
                }

                visited[r * m + c] = k;
                int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i], nc = c + dy[i];
                    q.push({nr, nc, k});
                }
            }

            ans += 1;
        }

        return -1;
    }
};
class Solution {
public:
    bool check(int N, int M, vector<vector<int>> Edges) {
        bool adj[N][N], cache[N][1 << N];
        memset(adj, 0, sizeof(adj));
        memset(cache, 0, sizeof(cache));

        for (auto e : Edges) {
            adj[e[0] - 1][e[1] - 1] = adj[e[1] - 1][e[0] - 1] = 1;
        }

        for (int i = 0; i < N; i++) {
            cache[i][1 << i] = 1;
        }

        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                if ((i >> j) & 1) {
                    for (int k = 0; k < N; k++) {
                        if (j != k and ((i >> k) & 1) and adj[j][k] and cache[k][i ^ (1 << j)]) {
                            cache[j][i] = 1;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (cache[i][(1 << N) - 1] == 1) {
                return true;
            }
        }

        return false;
    }
};
#include <bits/stdc++.h>
using namespace std;

const int mxn = 100100;
int degree[mxn];

class Solution {
public:
    bool pairExists (vector<vector<int>> &edges, int a, int b, int n) {
        bool exists = false;
        for (auto e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            if (x > y) swap (x, y);
            if (x == a and y == b) {
                exists = true;
                break;
            }
        }

        if (!exists) return false;

        bool noEdge[n];
        memset (noEdge, true, sizeof (noEdge));
        for (auto e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            if (x == a or x == b) noEdge[y] = false;
            if (y == a or y == b) noEdge[x] = false;
        }

        for (int i = 0; i < n; i++) {
            if (i != a and i != b and noEdge[i] and degree[i] % 2 == 0) {
                return false;
            }
        }

        return true;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        memset (degree, 0, n * 4);
        for (auto e : edges) {
            degree[e[0] - 1] += 1;
            degree[e[1] - 1] += 1;
        }

        vector<int> nodesWithOddDegree;
        for (int i = 0; i < n; i++) if (degree[i] & 1) nodesWithOddDegree.emplace_back (i);

        int odd = nodesWithOddDegree.size();
        if (odd == 0) return true;
        if ((odd & 1) or (odd > 4)) return false;

        if (odd == 2) {
            int a = nodesWithOddDegree[0], b = nodesWithOddDegree[1];
            return !pairExists (edges, a, b, n);
        }

        string s = "0011";
        do {
            bool noPairs = false;
            int x = 0, y;
            for (int i = 1; i < 4; i++) {
                if (s[i] == s[0]) {
                    y = i;
                    break;
                }
            }

            int a = nodesWithOddDegree[x], b = nodesWithOddDegree[y];
            noPairs |= pairExists (edges, a, b, n);

            int u = -1, v = -1;
            for (int i = 0; i < 4; i++) {
                if (i != x and i != y) {
                    if (u == -1) u = i;
                    else v = i;
                }
            }

            a = nodesWithOddDegree[u], b = nodesWithOddDegree[v];
            noPairs |= pairExists (edges, a, b, n);

            if (!noPairs) return true;
        } while (next_permutation (s.begin(), s.end()));

        return false;
    }
};
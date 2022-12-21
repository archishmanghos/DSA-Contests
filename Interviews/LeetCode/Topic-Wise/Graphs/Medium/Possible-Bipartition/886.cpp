#include <bits/stdc++.h>
using namespace std;

const int mxn = 2020;
class Solution {
public:
    vector<int> adj[mxn], colour;

    bool dfs (int node, int parent) {
        colour[node] = (parent == -1 ? 1 : 1 - colour[parent]);

        for (int child : adj[node]) {
            if (colour[child] != -1) {
                if (colour[child] == colour[node]) return false;
            } else {
                if (!dfs (child, node)) return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (auto e : dislikes) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        colour.assign (n + 1, -1);
        colour[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (colour[i] == -1) {
                if (!dfs (i, -1)) return false;
            }
        }

        return true;
    }
};
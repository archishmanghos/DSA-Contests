#include <bits/stdc++.h>
using namespace std;

const int mxn = 100100;
class Solution {
public:
    int subtree[mxn], countChild[mxn];
    vector<int> adj[mxn];
    void dfs1 (int node, int par) {
        countChild[node] = 1;
        for (int child : adj[node]) {
            if (child != par) {
                dfs1 (child, node);
                subtree[node] += subtree[child] + countChild[child];
                countChild[node] += countChild[child];
            }
        }
    }

    void dfs2 (int node, int par, int parAns, int n, vector<int> &ans) {
        ans[node] = subtree[node] + parAns + (n - countChild[node]);
        for (int child : adj[node]) {
            if (child != par) {
                dfs2 (child, node, ans[node] - (subtree[child] + countChild[child]), n, ans);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        memset (subtree, 0, n * sizeof(int));
        memset (countChild, 0, n * sizeof (int));

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1 (0, -1);
        int totalSum = 0;
        vector<int> ans (n);
        dfs2 (0, -1, 0, n, ans);
        return ans;
    }
};
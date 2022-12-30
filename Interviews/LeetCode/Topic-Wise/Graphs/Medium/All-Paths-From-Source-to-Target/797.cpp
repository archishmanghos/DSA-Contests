#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper (int node, int mask, vector<int> path, vector<vector<int>> &ans, vector<vector<int>> &graph) {
        if (node == graph.size() - 1) {
            path.push_back(node);
            ans.push_back(path);
            return;
        }

        if ((mask >> node) & 1) return;
        mask ^= (1 << node);
        path.push_back(node);

        for (int child : graph[node]) {
            helper (child, mask, path, ans, graph);
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        helper (0, 0, {}, ans, graph);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push (source);
        bool visited[n];
        memset (visited, false, sizeof (visited));

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) return true;
            if (visited[node]) continue;
            visited[node] = true;

            for (int child : adj[node]) {
                q.push(child);
            }
        }

        return false;
    }
};
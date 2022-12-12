#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 7;
class Solution {
   private:
    int insertionTime = 1, tin[mxn], low[mxn], vis[mxn], mark[mxn];
    void dfs(int node, int parent, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = insertionTime;
        insertionTime += 1;
        int cntChild = 0;

        for (int child : adj[node]) {
            if (child != parent) {
                if (vis[child]) {
                    low[node] = min(low[node], tin[child]);
                } else {
                    cntChild += 1;
                    dfs(child, node, adj);
                    low[node] = min(low[node], low[child]);
                    if (low[child] >= tin[node] and parent != -1) {
                        mark[node] = 1;
                    }
                }
            }
        }

        if (parent == -1 and cntChild > 1) {
            mark[node] = 1;
        }
    }

   public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        memset(tin, -1, sizeof(tin));
        memset(low, -1, sizeof(low));
        memset(vis, 0, sizeof(vis));
        memset(mark, 0, sizeof(mark));

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0) {
            return {-1};
        }

        return ans;
    }
};
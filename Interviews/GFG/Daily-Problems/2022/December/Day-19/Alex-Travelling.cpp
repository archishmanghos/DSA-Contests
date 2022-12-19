#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<vector<int>> adj[n];
        for (auto e : flights) {
            int u = e[0] - 1, v = e[1] - 1, wt = e[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push ({0, k - 1});
        int dist[n], mxn = 1e9;
        for (int i = 0; i < n; i++) dist[i] = 1e9;
        dist[k - 1] = 0;

        while (!pq.empty ()) {
            vector<int> node = pq.top();
            pq.pop();

            for (auto e : adj[node[1]]) {
                int child = e[0], wt = e[1];
                if (dist[child] > node[0] + wt) {
                    dist[child] = node[0] + wt;
                    pq.push({dist[child], child});
                }
            }
        }

        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            if (i != (k - 1)) {
                if (dist[i] == (int)1e9) return -1;
                ans = max (ans, dist[i]);
            }
        }

        if (ans == -1e9) return -1;
        return ans;
    }
};
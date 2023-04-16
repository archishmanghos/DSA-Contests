#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<pair<int, int>> adj[105];
    int vis[105];
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        int dist[n], INF = 1e9;
        for (int i = 0; i < n; i++) dist[i] = INF;
        dist[node1] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it[1];
            for (auto child : adj[node]) {
                if (dist[child.first] > dist[node] + child.second) {
                    dist[child.first] = dist[node] + child.second;

                    pq.push({dist[child.first], child.first});
                }
            }
        }

        if (dist[node2] == INF) return -1;
        return dist[node2];
    }
};
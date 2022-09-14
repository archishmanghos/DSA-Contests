class MST {
    int n;
    vector<int> parent, noderank;

public:
    void init(int _n) {
        n = _n;
        parent.assign(n, 0);
        noderank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int v) {
        if (parent[v] == v) return v;
        return parent[v] = findParent(parent[v]);
    }

    void unionNode(int u, int v) {
        u = findParent(u), v = findParent(v);
        if (noderank[u] <= noderank[v]) {
            parent[v] = u;
            if (noderank[u] == noderank[v]) noderank[u] += 1;
        } else {
            parent[u] = v;
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                edges.push_back({j[1], {i, j[0]}});
            }
        }

        sort(edges.begin(), edges.end());
        MST mst;
        mst.init(V);
        int mstCost = 0;
        for (int i = 0; i < edges.size(); i++) {
            int wt = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
            if (mst.findParent(u) != mst.findParent(v)) {
                mstCost += wt;
                mst.unionNode(u, v);
            }
        }

        return mstCost;
    }
};
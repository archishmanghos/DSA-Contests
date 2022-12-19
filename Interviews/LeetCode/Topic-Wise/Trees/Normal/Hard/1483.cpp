#include <bits/stdc++.h>
using namespace std;


const int mxn = 100100;
class TreeAncestor {
public:
    int l, parent[mxn], n, up[mxn][17];
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        for (int i = 0; i < n; i++) this->parent[i] = parent[i];
        l = 1;
        int n1 = n;
        while (n1 > 0) {
            l += 1;
            n1 >>= 1;
        }
        preProcess();
    }

    void preProcess () {
        for (int i = 0; i < n; i++) up[i][0] = parent[i];
        for (int j = 1; j < l; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1) up[i][j] = up[ up[i][j - 1] ][j - 1];
                else up[i][j] = -1;
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0 ; i < l; i++) {
            if ((k >> i) & 1) {
                if (up[node][i] != -1) node = up[node][i];
                else return -1;
            }
        }

        return node;
    }
};
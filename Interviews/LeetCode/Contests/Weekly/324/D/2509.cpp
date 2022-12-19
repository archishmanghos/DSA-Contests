#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int LOG = 30, m = queries.size();
        vector<int> ans (m);
        for (int j = 0; j < m; j++) {
            int u = queries[j][0], v = queries[j][1];
            int du = (int)log2(u), dv = (int)log2(v);
            if (du < dv) {
                swap (u, v);
                swap (du, dv);
            }

            int k = du - dv;
            u >>= k;
            int length = 1 + k;

            if (u == v) {
                ans[j] = length;
                continue;
            }

            for (int i = LOG; i >= 0; i--) {
                int pu = u >> i, pv = v >> i;
                if (pu != pv) {
                    length += 2 * i;
                    pu >>= i;
                    pv >>= i;
                    break;
                }
            }

            length += 2;
            ans[j] = length;
        }

        return ans;
    }
};
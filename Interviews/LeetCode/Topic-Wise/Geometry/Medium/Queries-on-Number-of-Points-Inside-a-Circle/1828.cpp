#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            int radiusSquare = queries[i][2] * queries[i][2];

            for (auto point : points) {
                int x1 = abs(point[0] - x);
                int y1 = abs(point[1] - y);
                int distSquare = x1 * x1 + y1 * y1;
                ans[i] +=  distSquare <= radiusSquare;
            }
        }

        return ans;
    }
};
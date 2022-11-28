#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int maxx = 1e5;
        vector<int> players(maxx + 1, 0), losers(maxx + 1, 0);

        for (auto i : matches) {
            int u = i[0], v = i[1];
            if (!players[u]) {
                players[u] = 1;
            }
            if (!players[v]) {
                players[v] = 1;
            }

            losers[v] += 1;
        }

        vector<vector<int>> ans(2);
        for (int i = 1; i <= maxx; i++) {
            if (players[i] and !losers[i]) {
                ans[0].push_back(i);
            }
            if (losers[i] == 1) {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};
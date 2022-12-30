#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<int> lastIdx (501, -1), lastIdxIdx (501, -1);

        for (int i = 0; i < groupSizes.size(); i++) {
            if (lastIdx[groupSizes[i]] == -1 or lastIdxIdx[lastIdx[groupSizes[i]]] == groupSizes[i]) {
                vector<int> temp(groupSizes[i], -1);
                temp[0] = i;
                ans.push_back(temp);
                lastIdx[groupSizes[i]] = ans.size() - 1;
                lastIdxIdx[ans.size() - 1] = 1;
            } else {
                ans[lastIdx[groupSizes[i]]][lastIdxIdx[lastIdx[groupSizes[i]]]] = i;
                lastIdxIdx[lastIdx[groupSizes[i]]] += 1;
            }
        }

        return ans;
    }
};
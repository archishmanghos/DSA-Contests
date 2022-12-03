#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string frequencySort(string s) {
        vector<int> cnt(75, 0);

        for (char c : s) {
            cnt[c - '0'] += 1;
        }

        vector<vector<int>> finCnt(75);
        for (int i = 0; i < 75; i++) {
            finCnt[i] = {cnt[i], i};
        }

        sort(finCnt.begin(), finCnt.end(), greater<vector<int>>());
        string ans = "";
        for (auto i : finCnt) {
            for (int j = 1; j <= i[0]; j++) {
                ans += (i[1] + '0');
            }
        }

        return ans;
    }
};
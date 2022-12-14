#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRange(string str, int n) {
        int i = 0, cnt[2] = {0}, ans = 0;
        vector<int> range = { -1};

        for (int j = 0; j < n; j++) {
            cnt[str[j] - '0'] += 1;
            while (cnt[1] > cnt[0]) {
                cnt[str[i++] - '0'] -= 1;
            }

            if (cnt[0] - cnt[1] > ans) {
                ans = cnt[0] - cnt[1];
                range = {i + 1, j + 1};
            }
        }

        return range;
    }
};
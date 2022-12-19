#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> count (n, vector<int> (26, 0));
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                count[i][c - 'a'] += 1;
            }
        }

        int pairs = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                bool flag = true;
                for (int k = 0; k < 26; k++) flag &= !((count[i][k] > 0) ^ (count[j][k] > 0));
                if (flag) pairs += 1;
            }
        }

        return pairs;
    }
};
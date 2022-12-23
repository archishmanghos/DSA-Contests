#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid (string s, vector<int> &cnt) {
        for (char c : s) {
            cnt[c - 'a'] -= 1;
            if (cnt[c - 'a'] < 0) return false;
        }

        return true;
    }

    int getScore (string s, vector<int> &score) {
        int ans = 0;
        for (char c : s) {
            ans += score[c - 'a'];
        }

        return ans;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        for (char c : letters) cnt[c - 'a'] += 1;
        int ans = 0, n = words.size();

        for (int mask = 0; mask < (1 << n); mask++) {
            bool ok = true;
            int curscore = 0;
            vector<int> temp = cnt;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    ok &= isValid (words[j], temp);
                    if (ok) curscore += getScore (words[j], score);
                    else {
                        curscore = 0;
                        break;
                    }
                }
            }

            ans = max (ans, curscore);
        }

        return ans;
    }
};
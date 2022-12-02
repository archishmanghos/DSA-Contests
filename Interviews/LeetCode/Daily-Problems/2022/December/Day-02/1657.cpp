#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt(26, 0), a, b;
        for (char c : word1) {
            cnt[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            a.push_back(cnt[i]);
        }

        cnt.assign(26, 0);
        for (char c : word2) {
            cnt[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            b.push_back(cnt[i]);
            if ((b[i] > 0 and a[i] == 0) or (b[i] == 0 and a[i] > 0)) {
                return false;
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
};
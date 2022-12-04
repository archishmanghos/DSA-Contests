#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isVowel(int x) {
        return x == 0 or x == 4 or x == 8 or x == 14 or x == 20;
    }

    string rearrange(string S, int N) {
        vector<int> cnt(26, 0);
        int vowels = 0;
        for (int i = 0; i < N; i++) {
            cnt[S[i] - 'a'] += 1;
            if (isVowel(S[i] - 'a')) {
                vowels += 1;
            }
        }

        if (abs(vowels - (N - vowels)) > 1) {
            return "-1";
        }

        int i = 1, j = 0, cur = 0;
        if (vowels < (N - vowels)) {
            cur = 1;
        }

        string ans = "";
        while (ans.size() < N) {
            if (cur) {
                while (cnt[i] == 0 or isVowel(i)) {
                    i += 1;
                }
                ans += (i + 'a');
                cnt[i] -= 1;
            } else {
                while (cnt[j] == 0 or !isVowel(j)) {
                    j += 1;
                }
                ans += (j + 'a');
                cnt[j] -= 1;
            }
            cur ^= 1;
        }

        return ans;
    }
};
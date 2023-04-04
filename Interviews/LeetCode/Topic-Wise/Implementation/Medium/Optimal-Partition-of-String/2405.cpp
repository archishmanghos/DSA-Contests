#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int answer = 1, cnt[26];
        memset (cnt, 0, sizeof(cnt));
        for (char c : s) {
            if (cnt[c - 'a']) {
                answer++;
                memset (cnt, 0, sizeof(cnt));
            }
            cnt[c - 'a']++;
        }

        return answer;
    }
};
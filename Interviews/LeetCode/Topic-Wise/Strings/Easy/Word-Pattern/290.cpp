#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ump;
        set<string> st;
        int j = 0;
        string t = "";
        s += ' ';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (j == pattern.size()) return false;
                if (ump.find(pattern[j]) != ump.end()) {
                    if (ump[pattern[j]] != t) return false;
                } else {
                    if (st.find(t) != st.end()) return false;
                    ump[pattern[j]] = t;
                    st.insert(t);
                }

                j += 1;
                t = "";
            } else {
                t += s[i];
            }
        }

        return j == pattern.size();
    }
};
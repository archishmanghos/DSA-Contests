#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int isItPossible(string S, string T, int M, int N) {
        string ns = "", nt = "";
        for (char c : S) {
            if (c != '#') {
                ns += c;
            }
        }
        for (char c : T) {
            if (c != '#') {
                nt += c;
            }
        }

        if (ns != nt)
            return 0;

        vector<vector<int>> pos1, pos2;
        for (int i = 0; i < M; i++) {
            if (S[i] != '#') {
                pos1.push_back({i, S[i] - 'A'});
            }
        }
        for (int i = 0; i < N; i++) {
            if (T[i] != '#') {
                pos2.push_back({i, T[i] - 'A'});
            }
        }

        for (int i = 0; i < pos1.size(); i++) {
            if (pos1[i][1] == 0) {
                if (pos1[i][0] < pos2[i][0]) {
                    return 0;
                }
            } else {
                if (pos1[i][0] > pos2[i][0]) {
                    return 0;
                }
            }
        }

        return 1;
    }
};
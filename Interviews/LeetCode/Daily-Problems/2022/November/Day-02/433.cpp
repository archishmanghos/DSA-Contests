class Solution {
public:
    int countSteps (string s, string &end, unordered_map<string, int> &ump) {
        if (s == end) return 0;

        char ch[4] = {'A', 'C', 'G', 'T'};
        int ans = 1e5;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] != ch[j]) {
                    string t = s.substr(0, i) + ch[j] + (i < 7 ? s.substr(i + 1) : "");
                    if (ump.find(t) != ump.end() and ump[t] == 1) {
                        ump[t] = 0;
                        ans = min(ans, countSteps(t, end, ump) + 1);
                        ump[t] = 1;
                    }
                }
            }
        }

        return ans;
    }
    int minMutation (string start, string end, vector<string>& bank) {
        unordered_map<string, int> ump;
        for (string s : bank) {
            ump[s] = 1;
        }

        int ans = countSteps(start, end, ump);
        return (ans > 10 ? -1 : ans);
    }
};
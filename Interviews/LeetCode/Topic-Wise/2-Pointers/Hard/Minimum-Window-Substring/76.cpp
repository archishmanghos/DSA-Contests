class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(58, 0);
        for (char c : t) {
            cnt[c - 'A'] += 1;
        }

        int dist = 1e9, start = -1;
        for (int i = 0, j = 0; j < s.size(); j++) {
            cnt[s[j] - 'A'] -= 1;
            if (cnt[s[j] - 'A'] < 0) {
                while (i < s.size() and cnt[s[i] - 'A'] < 0) {
                    cnt[s[i] - 'A'] += 1;
                    i++;
                }
            }

            bool ok = true;
            for (int k = 0; k < 58; k++) {
                ok &= cnt[k] <= 0;
            }

            if (ok and dist > (j - i + 1)) {
                dist = j - i + 1;
                start = i;
            }
        }

        return dist > s.size() ? "" : s.substr(start, dist);
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        for (string s : words) {
            ump[s] += 1;
        }

        int ans = 0, countPal = 0;
        for (string s : words) {
            if (ump[s] > 0) {
                string t = s;
                reverse(t.begin(), t.end());
                if (ump.find(t) != ump.end() and ((s != t and ump[t] > 0) or (s == t and ump[t] > 1))) {
                    int minCanTake = min(ump[s], ump[t]);
                    if (s == t) minCanTake >>= 1;
                    ans += minCanTake * 2 * 2;
                    ump[s] -= minCanTake;
                    ump[t] -= minCanTake;
                }
            }

            countPal += (ump[s] and s[0] == s[1]);
        }

        return ans + (countPal ? 2 : 0);
    }
};
class Solution {
public:
    int countOfSubstrings(string s, int k) {
        int n = s.size(), ans = 0, extra = 0;
        vector<int> cnt(26, 0);

        for (int i = 0; i < n; i++) {
            if (cnt[s[i] - 'a'] > 0) extra += 1;
            cnt[s[i] - 'a'] += 1;

            if (i >= k - 1) {
                if (extra == 1) ans += 1;

                if (cnt[s[i - k + 1] - 'a'] > 1) extra -= 1;
                cnt[s[i - k + 1] - 'a'] -= 1;
            }
        }

        return ans;
    }
};